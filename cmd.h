#!/bin/bash
#help cmd.help                                   # Help on commands
#Copyright (c) 2007 by Ralph A. Navarro Jr.
#PH: +1508-287-0190

$CMDENV
cd $CMDBIN

case "${1}x" in
    x)
        #help                                            # Default. List available commands.
        listCmd="ls --color=always"
        optionCmd=''
        ;;
    --findx|-fx)
        #help     [-f|--find <searchPattern>]            # Optional. List only files found matching <pattern>
        shift
        [ $# -eq 1 ] || { msg ERROR "Must supply <searchPattern> with -f option.  Exiting." ; exit 1 ; }
        searchPattern="$1"
        listCmd="find . -type f"
        optionCmd="| grep \"$searchPattern\" | xargs sed -n -e \"/^#help [A-Za-z]/ s/^#help \(.*$\)/\1/p\" | sort"
        ;;
    --helpx|-hx)
        #help     [-h|--help]                            # Optional. Print usage of the help command.
        listCmd="cmd.help"
        optionCmd="cmd.help"
        ;;
    --xrefx|-xx)
        #help     [-x|--xref <searchPattern>]            # Optional. Look for <searchPattern> in every file.
        shift
        [ $# -eq 1 ] || { msg ERROR "Must supply <searchPattern> with --xref option.  Exiting." ; exit 2 ; }
        searchPattern="$1"
        listCmd="find . -type f"
        optionCmd="| xargs grep \"$searchPattern\""
        ;;
    --listx|-lx|--allx|-ax)
        #help     [-l|--list|-a|--all]                   # Optional. List available commands and their descriptions
        shift
        listCmd="find -type f"
        optionCmd='| xargs sed -n -e "/^#help [A-Za-z]/ s/^#help \(.*$\)/\1/p" | sort'
        ;;
    --recentx)
        #help     [--recent [<number>]]                  # Optional. List most recent <number> of commands. Default=10
        shift
        numberOfCmds=10
        [ $# -gt 0 ] && numberOfCmds=$1
        shift
        ls -lt $CMDBIN | head -${numberOfCmds}
        ;;
    *x)
        #help     [<cmdName>]                            # Optional. Show syntax usage for command <cmdName>.
        cmdName="$1"
        [ ! -f "$cmdName" ] && { msg ERROR "Command '${CMDBIN}/${cmdName}' must exist.  Exiting." ; exit 3 ; }
        listCmd="sed -n -e 's/^\s*#help\s\(.*$\)/\1/p'"
        optionCmd='$1'
        ;;
esac

cmd="$listCmd $optionCmd"

eval $cmd

