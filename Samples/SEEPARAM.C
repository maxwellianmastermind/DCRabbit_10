/*
   Copyright (c) 2015, Digi International Inc.

   Permission to use, copy, modify, and/or distribute this software for any
   purpose with or without fee is hereby granted, provided that the above
   copyright notice and this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
/***********************************************************

      Samples\SEEPARAM.C

 This program demonstrates use of the Dynamic C program
 parameters. See also SAMPLES\MEMORY_USAGE.C

 The 'prog_param" structure has the following entries:

 prog_param

 ADDR24
 	RCB,RCE,    // root code 		(Begin and End)
	XCB,XCE,    // extended code 	(Begin and End)
	RDB,RDE,    // root data 		(Begin and End)
	XDB,XDE,    // extended data	(RAM) (Begin and End)
	RCDB,RCDE,  // Root constants (Begin and End)
   HPA;			// Highest program address (max of root code, const data and xmem code)


 unsigned int
   auxStkB,    // aux stack Begin (currently not used for Rabbit)
   auxStkE,    // end				 (currently not used for Rabbit)
	stkB,       // stack begin
	stkE,       // end
	freeB,  		// free begin		 (currently not used for Rabbit)
	freeE,  		// end				 (currently not used for Rabbit)
	heapB,  		// heap begin		 (currently not used for Rabbit)
	heapE;  		// end				 (currently not used for Rabbit)


	union ADDR24
		unsigned long l;        	// long for increment/decrement
  	   struct aaa
			struct a
				unsigned int addr;   // address
				unsigned char base;  // base  (XPC,DATASEG, or STACKSEG)
			   char flags;				// flags (currently not used for Rabbit)

************************************************************/
#class auto


void main()
{

	printf("root code begins at %04x:%04x, ends at %04x:%04x\n",
		prog_param.RCB.aaa.a.base,prog_param.RCB.aaa.a.addr,
		prog_param.RCE.aaa.a.base,prog_param.RCE.aaa.a.addr);

	printf("root data begins at %04x:%04x, ends at %04x:%04x\n",
		prog_param.RDB.aaa.a.base,prog_param.RDB.aaa.a.addr,
		prog_param.RDE.aaa.a.base,prog_param.RDE.aaa.a.addr);

	printf("xmem code begins at %04x:%04x, ends at %04x:%04x\n",
		prog_param.XCB.aaa.a.base,prog_param.XCB.aaa.a.addr,
		prog_param.XCE.aaa.a.base,prog_param.XCE.aaa.a.addr);

	printf("stack begins at %x, ends at %x\n",
		prog_param.stkB, prog_param.stkE);

#if __SEPARATE_INST_DATA__
	printf("constant data begins at %04x:%04x, ends at %04x:%04x\n",
		prog_param.RCDB.aaa.a.base,prog_param.RCDB.aaa.a.addr,
		prog_param.RCDE.aaa.a.base,prog_param.RCDE.aaa.a.addr);
#endif

	printf("highest used program address is %04x:%04x\n",
		prog_param.HPA.aaa.a.base,prog_param.HPA.aaa.a.addr);
}



