/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
 
*/


#include <stdio.h>

void main(){
	while(1){
		
	}



}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 2.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out &
// [3] 12225


// Terminal2:
// mohit@mohit-14IRL8:~$ cat /proc/12225/status
// Name:	a.out
// Umask:	0002
// State:	R (running)
// Tgid:	12225
// Ngid:	0
// Pid:	12225
// PPid:	7845
// TracerPid:	0
// Uid:	1000	1000	1000	1000
// Gid:	1000	1000	1000	1000
// FDSize:	256
// Groups:	4 24 27 30 46 100 114 1000 
// NStgid:	12225
// NSpid:	12225
// NSpgid:	12225
// NSsid:	7845
// Kthread:	0
// VmPeak:	    2604 kB
// VmSize:	    2548 kB
// VmLck:	       0 kB
// VmPin:	       0 kB
// VmHWM:	    1024 kB
// VmRSS:	    1024 kB
// RssAnon:	       0 kB
// RssFile:	    1024 kB
// RssShmem:	       0 kB
// VmData:	      92 kB
// VmStk:	     132 kB
// VmExe:	       4 kB
// VmLib:	    1748 kB
// VmPTE:	      44 kB
// VmSwap:	       0 kB
// HugetlbPages:	       0 kB
// CoreDumping:	0
// THP_enabled:	1
// untag_mask:	0xffffffffffffffff
// Threads:	1
// SigQ:	0/62585
// SigPnd:	0000000000000000
// ShdPnd:	0000000000000000
// SigBlk:	0000000000000000
// SigIgn:	0000000000000000
// SigCgt:	0000000000000000
// CapInh:	0000000000000000
// CapPrm:	0000000000000000
// CapEff:	0000000000000000
// CapBnd:	000001ffffffffff
// CapAmb:	0000000000000000
// NoNewPrivs:	0
// Seccomp:	0
// Seccomp_filters:	0
// Speculation_Store_Bypass:	thread vulnerable
// SpeculationIndirectBranch:	conditional enabled
// Cpus_allowed:	fff
// Cpus_allowed_list:	0-11
// Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
// Mems_allowed_list:	0
// voluntary_ctxt_switches:	0
// nonvoluntary_ctxt_switches:	243
// x86_Thread_features:	
// x86_Thread_features_locked:
