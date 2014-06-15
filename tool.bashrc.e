#!/bin/bash
#help tool.bashrc.edit                           # Edit the ~/.bashrc file
#Copyright (c) 2010 NavarroComputing LLC
#Author: Ralph A. Navarro Jr.
#AuthorPH: +1508-287-0190
#AuthorEmail: <ralph@navarrocomputing.com>
#License: MIT OSI

$CMDENV

msg BEGIN "$0 $*"

vim "${HOME}/.bashrc"

msg END "... done."

