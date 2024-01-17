#!/bin/sh
find -type f -iname '*.sh' -exec basename {} .sh ';'
