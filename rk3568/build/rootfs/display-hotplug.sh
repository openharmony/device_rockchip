#!/bin/sh

case $1 in
hdmi)
	echo off > /sys/class/drm/card0-eDP-1/status
	echo off > /sys/class/drm/card0-HDMI-A-1/status
	sleep 1
	echo on > /sys/class/drm/card0-HDMI-A-1/status
	;;
edp)
	echo off > /sys/class/drm/card0-HDMI-A-1/status
	sleep 1
	echo on > /sys/class/drm/card0-eDP-1/status
	;;
*)
	echo "Invalid parameter!"
	echo
	echo "Usage: display-hoplug.sh hdmi|edp"
	;;
esac
