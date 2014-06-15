#!/bin/bash
#help cmd.edit                                   # Edit a command
#Copyright (c) 2007,2008 NavarroComputing LLC
#Author: Ralph A. Navarro Jr.
#AuthorPH: +1508-287-0190
#AuthorEmail: <ralph@navarrocomputing.com>
#License: MIT OSI

$CMDENV

#help     <cmd>                                  # Required. Name of command to edit
[ $# -lt 1 ] && { msg ERROR "Must supply name of command to edit.  Exiting." ; exit 1 ; }
cmdName="$1"
cmdPathName="${CMDBIN}/$cmdName"

( msg BEGIN "$0 $*"

  [ ! -f "$cmdPathName" ] && touch "$cmdPathName"

  if (echo "$cmdPathName" | grep -q 'env$') ; then
    chmod 644 "$cmdPathName"
  else
    chmod 755 "$cmdPathName"
  fi
  
  if which gedit 2>/dev/null; then
    gedit "$cmdPathName" 2>/dev/null
  elif which gvim 1>/dev/null 2>/dev/null; then
    msg INFO "gedit is not found.  Trying gvim ..."
    gvim --nofork "$cmdPathName"
  elif which vim 1>/dev/null 2>/dev/null; then
    msg INFO "gvim is not found.  Trying vim ..." 
    vim "$cmdPathName"
  elif which vi 1>/dev/null 2>/dev/null; then
    msg INFO "vim is not found.  Trying vi ..."
    vi "$cmdPathName"
  else
    msg ERROR "No preferred editor is found.  You are on your own."
    exit 2
  fi

  msg END "... done"
) &
