#!/bin/bash
#help tool.bash_profile.edit                     # Edit the ~/.bash_profile file
#Copyright (c) 2010 NavarroComputing LLC
#Author: Ralph A. Navarro Jr.
#AuthorPH: +1508-287-0190
#AuthorEmail: <ralph@navarrocomputing.com>
#License: MIT OSI

$CMDENV

msg BEGIN "$0 $*"

vim "${HOME}/.bash_profile"

msg END "... done."

