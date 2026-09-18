/*
 * Copyright 1996 by Frederic Lepied, France. <Frederic.Lepied@sugix.frmug.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is  hereby granted without fee, provided that
 * the  above copyright   notice appear  in   all  copies and  that both  that
 * copyright  notice   and   this  permission   notice  appear  in  supporting
 * documentation, and that   the  name of  the authors  not  be  used  in
 * advertising or publicity pertaining to distribution of the software without
 * specific,  written      prior  permission.     The authors  make  no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * THE AUTHORS DISCLAIM ALL   WARRANTIES WITH REGARD  TO  THIS SOFTWARE,
 * INCLUDING ALL IMPLIED   WARRANTIES OF MERCHANTABILITY  AND   FITNESS, IN NO
 * EVENT  SHALL THE AUTHORS  BE   LIABLE   FOR ANY  SPECIAL, INDIRECT   OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA  OR PROFITS, WHETHER  IN  AN ACTION OF  CONTRACT,  NEGLIGENCE OR OTHER
 * TORTIOUS  ACTION, ARISING    OUT OF OR   IN  CONNECTION  WITH THE USE    OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include "xinput.h"
#include <string.h>

#define INVALID_EVENT_TYPE	-1

static int           motion_type = INVALID_EVENT_TYPE;
static int           button_press_type = INVALID_EVENT_TYPE;
static int           button_release_type = INVALID_EVENT_TYPE;
static int           key_press_type = INVALID_EVENT_TYPE;
static int           key_release_type = INVALID_EVENT_TYPE;
static int           proximity_in_type = INVALID_EVENT_TYPE;
static int           proximity_out_type = INVALID_EVENT_TYPE;
static int           device_presence_type = INVALID_EVENT_TYPE;

static Window create_win(Display *dpy)
{
    XEvent event;
    Window win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 200,
				     200, 0, 0, WhitePixel(dpy, 0));
    Window subwindow = XCreateSimpleWindow(dpy, win, 50, 50, 50, 50, 0, 0,
					   BlackPixel(dpy, 0));

    XMapWindow(dpy, subwindow);
    XSelectInput(dpy, win, ExposureMask);
    XMapWindow(dpy, win);
    XFlush(dpy);

    XMaskEvent(dpy, ExposureMask, &event);
    XSelectInput(dpy, win, 0);
    XSync(dpy, False);

    return win;
}

static int
register_events(Display		*dpy,
		Window		win,
		XDeviceInfo	*info,
		char		*dev_name,
		Bool		handle_proximity)
{
    int			number = 0;	/* number of events registered */
    XEventClass		event_list[7];
    int			i;
    XDevice		*device;
    XInputClassInfo	*ip;

    device = XOpenDevice(dpy, info->id);

    if (!device) {
	fprintf(stderr, "unable to open device '%s'\n", dev_name);
	return 0;
    }

    DevicePresence(dpy, device_presence_type, event_list[number]); number++;

    if (device->num_classes > 0) {
	for (ip = device->classes, i=0; i<info->num_classes; ip++, i++) {
	    switch (ip->input_class) {
	    case KeyClass:
		DeviceKeyPress(device, key_press_type, event_list[number]); number++;
		DeviceKeyRelease(device, key_release_type, event_list[number]); number++;
		break;

	    case ButtonClass:
		DeviceButtonPress(device, button_press_type, event_list[number]); number++;
		DeviceButtonRelease(device, button_release_type, event_list[number]); number++;
		break;

	    case ValuatorClass:
		DeviceMotionNotify(device, motion_type, event_list[number]); number++;
		if (handle_proximity) {
		    ProximityIn(device, proximity_in_type, event_list[number]); number++;
		    ProximityOut(device, proximity_out_type, event_list[number]); number++;
		}
		break;

	    default:
		fprintf(stderr, "unknown class\n");
		break;
	    }
	}

	if (XSelectExtensionEvent(dpy, win, event_list, number)) {
	    fprintf(stderr, "error selecting extended events\n");
	    return 0;
	}
    }
    return number;
}

static void
print_events(Display	*dpy)
{
    XEvent        Event;

    setvbuf(stdout, NULL, _IOLBF, 0);

    while(1) {
	XNextEvent(dpy, &Event);

	if (Event.type == Expose) {
	    /* noop */
	} else if (Event.type == motion_type) {
	    int	loop;
	    XDeviceMotionEvent *motion = (XDeviceMotionEvent *) &Event;

	    printf("motion ");

	    for(loop=0; loop<motion->axes_count; loop++) {
		printf("a[%d]=%d ", motion->first_axis + loop, motion->axis_data[loop]);
	    }
	    printf("\n");
	} else if ((Event.type == button_press_type) ||
		   (Event.type == button_release_type)) {
	    int	loop;
	    XDeviceButtonEvent *button = (XDeviceButtonEvent *) &Event;

	    printf("button %s %d ", (Event.type == button_release_type) ? "release" : "press  ",
		   button->button);

	    for(loop=0; loop<button->axes_count; loop++) {
		printf("a[%d]=%d ", button->first_axis + loop, button->axis_data[loop]);
	    }
	    printf("\n");
	} else if ((Event.type == key_press_type) ||
		   (Event.type == key_release_type)) {
	    int	loop;
	    XDeviceKeyEvent *key = (XDeviceKeyEvent *) &Event;

	    printf("key %s %d ", (Event.type == key_release_type) ? "release" : "press  ",
		   key->keycode);

	    for(loop=0; loop<key->axes_count; loop++) {
		printf("a[%d]=%d ", key->first_axis + loop, key->axis_data[loop]);
	    }
	    printf("\n");
	} else if ((Event.type == proximity_out_type) ||
		   (Event.type == proximity_in_type)) {
	    int	loop;
	    XProximityNotifyEvent *prox = (XProximityNotifyEvent *) &Event;

	    printf("proximity %s ", (Event.type == proximity_in_type) ? "in " : "out");

	    for(loop=0; loop<prox->axes_count; loop++) {
		printf("a[%d]=%d ", prox->first_axis + loop, prox->axis_data[loop]);
	    }
	    printf("\n");
	} else if (Event.type == device_presence_type) {
	    XDevicePresenceNotifyEvent *p = (XDevicePresenceNotifyEvent*) &Event;
	    printf("presence id %ld devchange %d control %ld", p->deviceid, p->devchange, p->control);
	} else {
	    printf("what's that %d\n", Event.type);
	}
    }
}

int
test(Display	*display,
     int	argc,
     char	*argv[],
     char	*name,
     char	*desc)
{
    XDeviceInfo		*info;
    int			 idx;
    Bool		 handle_proximity = False;
    Bool		 use_window = False;

    for (idx = 0; idx < argc; idx++) {
	if (strcmp("-proximity", argv[idx]) == 0) {
	    handle_proximity = True;
	} else if (strcmp("-window", argv[idx]) == 0) {
	    use_window = True;
	} else if (argv[idx][0] == '-') {
	    fprintf(stderr, "usage: xinput %s %s\n", name, desc);
	    return EXIT_FAILURE;
	} else {
	    break;
	}
    }

    if (idx == argc) {
	fprintf(stderr, "usage: xinput %s %s\n", name, desc);
	return EXIT_FAILURE;
    }
    info = find_device_info(display, argv[idx], True);

    if (!info) {
	fprintf(stderr, "unable to find device '%s'\n", argv[idx]);
	return EXIT_FAILURE;
    } else {
	Window win = use_window ? create_win(display) : RootWindow(display, DefaultScreen(display));

	if (register_events(display, win, info, argv[idx], handle_proximity)) {
	    print_events(display);
	}
	else {
	    fprintf(stderr, "no event registered...\n");
	    return EXIT_FAILURE;
	}
    }
    return EXIT_FAILURE;
}

/* end of test.c */
