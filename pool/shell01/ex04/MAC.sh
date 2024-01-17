#!/bin/sh
ifconfig | grep ether | awk '{$1="" ; $3=""; $4=""; $5=""; print $0;}' | tr -d ' '
