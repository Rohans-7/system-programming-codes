/*
============================================================================
Name : 2.c
Author : Rohan Sonawane
Description : Write a simple program to execute in an infinite loop at the backg	round. Go to /proc directory and
	identify all the process related information in the corresponding proc d	irectory
Date: 11th Aug, 2024.
============================================================================
*/
#include<stdio.h>

int main(){
	for(;;){
		printf("a\n");
	}
	return 0;
}

/*
 Input and Output:
Input:
cd: ps aux | grep infi_prog
Output: 
rohan-s+    3494  0.0  0.1  26084 12672 pts/0    Sl+  19:22   0:00 vim infi_prog.c
rohan-s+    3573  0.0  0.0   9204  2304 pts/2    S+   19:25   0:00 grep --color=auto infi_prog

cd: cat /proc/3494/status
output: 
Name:	vim
Umask:	0002
State:	S (sleeping)
Tgid:	3494
Ngid:	0
Pid:	3494
PPid:	3412
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 118 1000
NStgid:	3494
NSpid:	3494
NSpgid:	3494
NSsid:	3412
VmPeak:	   26164 kB
VmSize:	   26084 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	   12672 kB
VmRSS:	   12672 kB
RssAnon:	    5248 kB
RssFile:	    7424 kB
RssShmem:	       0 kB
VmData:	    5552 kB
VmStk:	     132 kB
VmExe:	    2936 kB
VmLib:	    6108 kB
VmPTE:	      88 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	2
SigQ:	1/30554
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000003000
SigCgt:	000000016f8a4eff
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ff
Cpus_allowed_list:	0-7
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	92
nonvoluntary_ctxt_switches:	2
 */
