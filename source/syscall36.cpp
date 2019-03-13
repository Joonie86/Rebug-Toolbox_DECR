
#include "common.h"
#include "peek_poke.h"
#include "hvcall.h"
#include "mm.h"
#include <string.h>
#include "lv2.h"
u64 mmap_lpar_addr;


extern u8 dex_mode;
extern float c_firmware;
extern u8 rex_compatible;
//extern u8 dump_mode;
//extern u8 bdisk_mode;

/*
int map_lv1()
{
	int result = lv1_undocumented_function_114(HV_START_OFFSET, HV_PAGE_SIZE, HV_SIZE, &mmap_lpar_addr);
	if (result != 0) return 0;

	result =  mm_map_lpar_memory_region(mmap_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
	if (result) return 0;

	return 1;
}

int map_lv1_ss()
{
	int result = lv1_undocumented_function_114(HV_START_OFFSET2, HV_PAGE_SIZE, HV_SIZE, &mmap_lpar_addr);
	if (result != 0) return 0;

	result =  mm_map_lpar_memory_region(mmap_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
	if (result) return 0;

	return 1;
}

void unmap_lv1()
{
	if (mmap_lpar_addr != 0) lv1_undocumented_function_115(mmap_lpar_addr);
}
*/
int map_lv1_355()
{
	int result = lv1_355_undocumented_function_114(HV_START_OFFSET, HV_PAGE_SIZE, HV_SIZE, &mmap_lpar_addr);
	if (result != 0) return 0;

	result =  mm_355_map_lpar_memory_region(mmap_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
	if (result) return 0;

	return 1;
}

int map_lv1_ss_355()
{
	int result = lv1_355_undocumented_function_114(HV_START_OFFSET2, HV_PAGE_SIZE, HV_SIZE, &mmap_lpar_addr);
	if (result != 0) return 0;

	result =  mm_355_map_lpar_memory_region(mmap_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
	if (result) return 0;

	return 1;
}

void unmap_lv1_355()
{
	if (mmap_lpar_addr != 0) lv1_355_undocumented_function_115(mmap_lpar_addr);
}

void generic_patches()
{
	//Remove Lv2 memory protection
	if(c_firmware==3.55f)
	{
		install_new_poke();
		if (!map_lv1_355()) { remove_new_poke(); return; }
		Lv2Syscall2(7, HV_BASE + HV_OFFSET +  0, 0x0000000000000001ULL);
		Lv2Syscall2(7, HV_BASE + HV_OFFSET +  8, 0xe0d251b556c59f05ULL);
		Lv2Syscall2(7, HV_BASE + HV_OFFSET + 16, 0xc232fcad552c80d7ULL);
		Lv2Syscall2(7, HV_BASE + HV_OFFSET + 24, 0x65140cd200000000ULL);
		unmap_lv1_355();
		remove_new_poke();
	}
	if(c_firmware==4.21f)
	{
		Lv2Syscall2(9, HV_START_OFFSET_421 +  0, 0x0000000000000001ULL);
		Lv2Syscall2(9, HV_START_OFFSET_421 +  8, 0xe0d251b556c59f05ULL);
		Lv2Syscall2(9, HV_START_OFFSET_421 + 16, 0xc232fcad552c80d7ULL);
		Lv2Syscall2(9, HV_START_OFFSET_421 + 24, 0x65140cd200000000ULL);
	}
	
	if( (c_firmware>=4.30f && c_firmware<=4.53f) )
	{
		Lv2Syscall2(9, HV_START_OFFSET_430 +  0, 0x0000000000000001ULL);
		Lv2Syscall2(9, HV_START_OFFSET_430 +  8, 0xe0d251b556c59f05ULL);
		Lv2Syscall2(9, HV_START_OFFSET_430 + 16, 0xc232fcad552c80d7ULL);
		Lv2Syscall2(9, HV_START_OFFSET_430 + 24, 0x65140cd200000000ULL);
	}

	if( (c_firmware>=4.55f && c_firmware<=4.84f) )
	{
		Lv2Syscall2(9, HV_START_OFFSET_455 +  0, 0x0000000000000001ULL);
		Lv2Syscall2(9, HV_START_OFFSET_455 +  8, 0xe0d251b556c59f05ULL);
		Lv2Syscall2(9, HV_START_OFFSET_455 + 16, 0xc232fcad552c80d7ULL);
		Lv2Syscall2(9, HV_START_OFFSET_455 + 24, 0x65140cd200000000ULL);
	}

	if(!dex_mode)
	{
		if(c_firmware==3.55f)
		{
			Lv2Syscall2(7, 0x8000000000055EA0ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000055F64ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000055F10ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000055F18ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000007AF64ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000007AF78ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.21f)
		{
			Lv2Syscall2(7, 0x8000000000057020ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x80000000000570E4ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000057090ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000057098ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005AA54ULL, 0x2F83000060000000ULL ); // fix 80010009 error
			Lv2Syscall2(7, 0x800000000005AA68ULL, 0x2F83000060000000ULL ); // fix 80010019 error
		}

		if(c_firmware==4.30f)
		{
			Lv2Syscall2(7, 0x8000000000057170ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000057234ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x80000000000571E0ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x80000000000571E8ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005ABA4ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005ABB8ULL, 0x2F83000060000000ULL );
		}


		if(c_firmware==4.31f)
		{
			Lv2Syscall2(7, 0x8000000000057174ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005723CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error

			Lv2Syscall2(7, 0x80000000000571E8ULL, 0x600000002F840004ULL );
			Lv2Syscall2(7, 0x80000000000571F0ULL, 0x48000098E8629870ULL );
			Lv2Syscall2(7, 0x800000000005ABACULL, 0x60000000E8610188ULL );
			Lv2Syscall2(7, 0x800000000005ABA0ULL, 0x600000005463063EULL );

		}

		if(c_firmware==4.40f)
		{
			Lv2Syscall2(7, 0x80000000000560BCULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000056180ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error +C4
			Lv2Syscall2(7, 0x800000000005612CULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000056134ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x8000000000059AF0ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x8000000000059B04ULL, 0x2F83000060000000ULL );
		}
		
#define pokeq(a, b)		(Lv2Syscall2(7, a, b))
		
		if(c_firmware==4.41f)
		{
			Lv2Syscall2(7, 0x80000000000560C0ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000056184ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000056130ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000056138ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x8000000000059AF4ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x8000000000059B08ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.46f)
		{
			Lv2Syscall2(7, 0x80000000000560C0ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000056184ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000056130ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000056138ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x8000000000059AF4ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x8000000000059B08ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.50f)
		{
			Lv2Syscall2(7, 0x80000000000560BCULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000056180ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x800000000005612CULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000056134ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x8000000000059AF0ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x8000000000059B04ULL, 0x2F83000060000000ULL );
		}
		
		
		if(c_firmware==4.53f)
		{
			Lv2Syscall2(7, 0x80000000000560C0ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000056184ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000056130ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000056138ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x8000000000059AF4ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x8000000000059B08ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.55f)
		{
			Lv2Syscall2(7, 0x8000000000056380ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000056444ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x80000000000563F0ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x80000000000563F8ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005A2ECULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005A300ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.60f)
		{
			Lv2Syscall2(7, 0x8000000000056588ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005664CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x80000000000565F8ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000056600ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005A654ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005A668ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.65f || c_firmware==4.66f)
		{
			Lv2Syscall2(7, 0x800000000005658CULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000056650ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x80000000000565FCULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000056604ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005A658ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005A66CULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x8000000000056230ULL, 0x386000012F830000ULL ); // ignore LIC.DAT check			
		}
		if(c_firmware==4.70f)
		{
			Lv2Syscall2(7, 0x8000000000056588ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005664CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x80000000000565F8ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000056600ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005A6DCULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005A6F0ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005622CULL, 0x386000012F830000ULL ); // ignore LIC.DAT check			
		}
		if(c_firmware==4.75f || c_firmware==4.76f || c_firmware==4.78f || c_firmware==4.81f || c_firmware==4.82f || c_firmware==4.83f || c_firmware==4.84f)
		{
			Lv2Syscall2(7, 0x800000000005658CULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000056650ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x80000000000565FCULL, 0x419E00D860000000ULL ); // Original: 0x419E00D8419D00C0ULL
			Lv2Syscall2(7, 0x8000000000056604ULL, 0x2F84000448000098ULL ); // Original: 0x2F840004409C0048ULL //PATCH_JUMP
			Lv2Syscall2(7, 0x800000000005A6E0ULL, 0x2F83000060000000ULL ); // fix 80010009 error  Original: 0x2F830000419E00ACULL
			Lv2Syscall2(7, 0x800000000005A6F4ULL, 0x2F83000060000000ULL ); // fix 80010009 error  Original: 0x2F830000419E00ACULL
			Lv2Syscall2(7, 0x8000000000056230ULL, 0x386000012F830000ULL ); // ignore LIC.DAT check			
		}
	}
	else if (dex_mode)
	{ //DEH

		if(c_firmware==3.15f)
		{
			Lv2Syscall2(7, 0x800000000005ACA8ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005AD6CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x800000000005AD15ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x800000000005AD20ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x80000000000535E0ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x80000000000535F4ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==3.55f)
		{
			Lv2Syscall2(7, 0x800000000005978CULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000059850ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x80000000000597FCULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000059804ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000007EF5CULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000007EF70ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.21f)
		{
			Lv2Syscall2(7, 0x800000000005A938ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005A9FCULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x800000000005A9A8ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x800000000005A9B0ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005E36CULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005E380ULL, 0x2F83000060000000ULL );
		}
		
		if(c_firmware==4.30f)
		{
			Lv2Syscall2(7, 0x800000000005AA88ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005AB4CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x800000000005AAF8ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x800000000005AB00ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005E4BCULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005E4D0ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.41f)
		{
			Lv2Syscall2(7, 0x80000000000599D8ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000059A9CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000059A48ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000059A50ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005D40CULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005D420ULL, 0x2F83000060000000ULL );

		}

		if(c_firmware==4.46f)
		{
			Lv2Syscall2(7, 0x80000000000599D8ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000059A9CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000059A48ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000059A50ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005D40CULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005D420ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.50f)
		{
			Lv2Syscall2(7, 0x8000000000059A8CULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000059B50ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000059AFCULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000059B04ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005D4C0ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005D4D4ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.53f)
		{
			Lv2Syscall2(7, 0x8000000000059A90ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000059B54ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000059B00ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000059B08ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005D4C4ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005D4D8ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.55f)
		{
			Lv2Syscall2(7, 0x8000000000059D50ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x8000000000059E14ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000059DC0ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000059DC8ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005DCB8ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005DCD0ULL, 0x2F83000060000000ULL );
		}

		if(c_firmware==4.60f)
		{
			Lv2Syscall2(7, 0x8000000000059F58ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005A01CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000059FC8ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000059FD0ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005E020ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005E038ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x8000000000059BFCULL, 0x386000012F830000ULL ); // ignore LIC.DAT check

		}

		if(c_firmware==4.65f || c_firmware==4.66f)
		{			
			Lv2Syscall2(7, 0x8000000000059F5CULL, 0x63FF003D60000000ULL ); // fix 8001003D error  Original: 0x63FF003D419EFFD4ULL
			Lv2Syscall2(7, 0x800000000005A020ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error  Original: 0x3FE0800163FF003EULL
			Lv2Syscall2(7, 0x8000000000059FCCULL, 0x419E00D860000000ULL ); // Original: 0x419E00D8419D00C0ULL
			Lv2Syscall2(7, 0x8000000000059FD4ULL, 0x2F84000448000098ULL ); // Original: 0x2F840004409C0048ULL //PATCH_JUMP
			Lv2Syscall2(7, 0x800000000005E028ULL, 0x2F83000060000000ULL ); // fix 80010009 error  Original: 0x2F830000419E00ACULL
			Lv2Syscall2(7, 0x800000000005E03CULL, 0x2F83000060000000ULL ); // fix 80010009 error  Original: 0x2F830000419E00ACULL
			Lv2Syscall2(7, 0x8000000000059C00ULL, 0x386000012F830000ULL ); // ignore LIC.DAT check
        }

		if(c_firmware==4.70f)
		{		
			Lv2Syscall2(7, 0x8000000000059F58ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005A01CULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x8000000000059FC8ULL, 0x419E00D860000000ULL );
			Lv2Syscall2(7, 0x8000000000059FD0ULL, 0x2F84000448000098ULL );
			Lv2Syscall2(7, 0x800000000005E0ACULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x800000000005E0C0ULL, 0x2F83000060000000ULL );
			Lv2Syscall2(7, 0x8000000000059BFCULL, 0x386000012F830000ULL ); // ignore LIC.DAT check		
		}

		if(c_firmware==4.75f || c_firmware==4.76f || c_firmware==4.78f || c_firmware==4.81f || c_firmware==4.82f || c_firmware==4.83f || c_firmware==4.84f)
		{		
			Lv2Syscall2(7, 0x80000000000599E4ULL, 0x63FF003D60000000ULL ); // fix 8001003D error
			Lv2Syscall2(7, 0x800000000005A408ULL, 0x3FE080013BE00000ULL ); // fix 8001003E error
			Lv2Syscall2(7, 0x800000000005A3B4ULL, 0x419E00D860000000ULL ); // Original: 0x419E00D8419D00C0ULL
			Lv2Syscall2(7, 0x800000000005A3BCULL, 0x2F84000448000098ULL ); // Original: 0x2F840004409C0048ULL //PATCH_JUMP
			Lv2Syscall2(7, 0x800000000005E498ULL, 0x2F83000060000000ULL ); // fix 80010009 error  Original: 0x2F830000419E00ACULL
			Lv2Syscall2(7, 0x800000000005E4ACULL, 0x2F83000060000000ULL ); // fix 80010009 error  Original: 0x2F830000419E00ACULL
			Lv2Syscall2(7, 0x8000000000059FE8ULL, 0x386000012F830000ULL ); // ignore LIC.DAT check			
		}
	}
}

void poke_lv1(u64 _addr, u64 _val)
{
	//if(dex_mode && c_firmware==4.21f) return;
	//if(bdisk_mode && c_firmware>=4.21f) return;

	if((rex_compatible==0) && (c_firmware==3.55f || c_firmware==3.41f))
	{
		u64 _offset = (_addr & 0xFFFFFFFFFFFFF000ULL);
		install_new_poke();
		lv1_355_undocumented_function_114(_offset, HV_PAGE_SIZE, HV_SIZE, &mmap_lpar_addr);
		mm_355_map_lpar_memory_region(mmap_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);

		Lv2Syscall2(7, HV_BASE + (_addr - _offset), _val);

		remove_new_poke();
		lv1_355_undocumented_function_115(mmap_lpar_addr);
	}
	else
	{
		Lv2Syscall2(9, _addr, _val);
	}
}

u64 peek_lv1(u64 _addr)
{
	//if(dex_mode && c_firmware==4.21f) { return 0; }
	//if(bdisk_mode && c_firmware>=4.21f) { return 0; }

	if
	((rex_compatible==0) && (c_firmware==3.55f || c_firmware==3.41f))
	{
		u64 _offset = (_addr & 0xFFFFFFFFFFFFF000ULL);
		install_new_poke();
		lv1_355_undocumented_function_114(_offset, HV_PAGE_SIZE, HV_SIZE, &mmap_lpar_addr);
		mm_355_map_lpar_memory_region(mmap_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);

		u64 ret = Lv2Syscall1(6, HV_BASE + (_addr - _offset));

		remove_new_poke();
		lv1_355_undocumented_function_115(mmap_lpar_addr);
		return ret;
	}
	else
	{
		u64 ret = Lv2Syscall1(8, _addr);
		return ret;
	}
}

/*
// the one from multiMAN 4.50
void poke_lv1(u64 _addr, u64 _val)
{
	(void)_addr; (void) _val;
	if(cobra_mode) return;
//#ifndef COBRA_MODE
	//if(dex_mode && c_firmware==4.21f && bdisk_mode) return;
	if(c_firmware>4.75f) { return; }
	if(c_firmware>=4.21f)// && !bdisk_mode)
	{
		Lv2Syscall2(9, _addr, _val);
	}
	else
	{
		u64 mmap_lpar_addr2=0;
		u64 _offset = (_addr & 0xFFFFFFFFFFFFF000ULL);
		install_new_poke();
		lv1_355_undocumented_function_114(_offset, HV_PAGE_SIZE, HV_SIZE, &mmap_lpar_addr2);
		if(mmap_lpar_addr2)
		{
			mm_355_map_lpar_memory_region(mmap_lpar_addr2, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
			Lv2Syscall2(7, HV_BASE + (_addr - _offset), _val);
			lv1_355_undocumented_function_115(mmap_lpar_addr2);
		}
		remove_new_poke();
	}
//#endif
}

u64 peek_lv1(u64 _addr)
{
	(void) _addr;
	if(cobra_mode) return 0;
#ifndef COBRA_MODE
	//if(dex_mode   && c_firmware==4.21f && bdisk_mode) { return 0xDEAD0BABE0BEEF00ULL; }
	//if(bdisk_mode && c_firmware>=4.21f) { return 0xDEAD0BABE0BEEF00ULL; }
	if(c_firmware>=4.21f)// && !bdisk_mode)
	{
		u64 ret = Lv2Syscall1(8, _addr);
		return ret;
	}
	else
	{
		u64 mmap_lpar_addr2=0;
		u64 _offset = (_addr & 0xFFFFFFFFFFFFF000ULL);
		u64 ret = 0xDEAD0BABE0BEEF01ULL;
		install_new_poke();
		lv1_355_undocumented_function_114(_offset, HV_PAGE_SIZE, HV_SIZE, &mmap_lpar_addr2);
		if(mmap_lpar_addr2)
		{
			mm_355_map_lpar_memory_region(mmap_lpar_addr2, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
			ret = Lv2Syscall1(6, HV_BASE + (_addr - _offset));
			lv1_355_undocumented_function_115(mmap_lpar_addr2);
		}
		remove_new_poke();
		return ret;
	}
}
*/
// fix broken bd-movie playback by rewriting VTRM flash

/*
int vtrm_retrieve(u8* data)
{

	int ret;
	u64 vuart_lpar_addr, nread, muid, nwritten;
	install_new_poke();
	ret = lv1_allocate_memory(4096, 0x0C, 0, &vuart_lpar_addr, &muid);
 	if (ret) {remove_new_poke(); return (ret);}

	ret =  mm_map_lpar_memory_region(vuart_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
 	if (ret) { {lv1_release_memory(vuart_lpar_addr);} remove_new_poke(); return (ret);}

	uint64_t laid, paid;
	u16 len;

	laid = LAID;
	paid = PAID;

	struct ps3dm_vtrm_retrieve retrieve;
	u8*p=(u8*)&retrieve;
	memset(&retrieve, 0, sizeof(retrieve));

	ps3dm_init_header(&retrieve.dm_hdr, 1, PS3DM_FID_VTRM,
	    sizeof(retrieve) - sizeof(struct ps3dm_header),
	    sizeof(retrieve) - sizeof(struct ps3dm_header));

	ps3dm_init_ss_header(&retrieve.ss_hdr, PS3DM_PID_VTRM_RETRIEVE, laid, paid);

	retrieve.nth = 0;

	len = sizeof(retrieve);

	for(u16 n = 0; n < len; n += 8)
	{
		static u64 value;
		memcpy(&value, &p[n], 8);
		lv2_poke(HV_BASE + (u64) n, value);
		__asm__("sync");
		value =  Lv2Syscall1(6, 0x8000000000000000ULL);
	}

	ret = lv1_write_virtual_uart(DISPMGR_VUART_PORT, vuart_lpar_addr, len, &nwritten);
	if (ret < 0) goto leave;

	ret = vuart_wait_for_rx_data(DISPMGR_VUART_PORT);
	if (ret < 0) goto leave;

	ret = lv1_read_virtual_uart(DISPMGR_VUART_PORT, vuart_lpar_addr, 4096, &nread);
	if (ret < 0) goto leave;

	if(nread>len) nread=len;

	for(u16 n = 0; n < len; n += 8)
	{
		static u64 value;
		value=Lv2Syscall1(6, HV_BASE + (u64) n);
		memcpy(&p[n], &value, 8);
	}

	if(nread>=72)
	{
		memcpy(data, &p[nread-72], 40);
		nread=40;
	}

	ret=nread;

leave:
	{lv1_undocumented_function_115(vuart_lpar_addr);}
	{lv1_release_memory(vuart_lpar_addr);}
	remove_new_poke();
	return ret;
}

int vtrm_update(u8* data)
{

	int ret;
	u64 vuart_lpar_addr, muid, nwritten;
	install_new_poke();
	ret = lv1_allocate_memory(4096, 0x0C, 0, &vuart_lpar_addr, &muid);
 	if (ret) {remove_new_poke(); return (ret);}

	ret =  mm_map_lpar_memory_region(vuart_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
 	if (ret) { {lv1_release_memory(vuart_lpar_addr);} remove_new_poke(); return (ret);}

	uint64_t laid, paid;
	u16 len;

	laid = LAID;
	paid = PAID;

	struct ps3dm_vtrm_store_with_update store_with_update;
	u8*p=(u8*)&store_with_update;
	memset(&store_with_update, 0, sizeof(store_with_update));

	ps3dm_init_header(&store_with_update.dm_hdr, 1, PS3DM_FID_VTRM,
	    sizeof(store_with_update) - sizeof(struct ps3dm_header),
	    sizeof(store_with_update) - sizeof(struct ps3dm_header));

	ps3dm_init_ss_header(&store_with_update.ss_hdr, PS3DM_PID_VTRM_STORE_WITH_UPDATE, laid, paid);

	memset(store_with_update.data, 0, sizeof(store_with_update.data));
	memcpy(store_with_update.data, data, 40);

	len = sizeof(store_with_update);

	for(u16 n = 0; n < len; n += 8)
	{
		static u64 value;
		memcpy(&value, &p[n], 8);
		lv2_poke(HV_BASE + (u64) n, value);
		__asm__("sync");
		value =  Lv2Syscall1(6, 0x8000000000000000ULL);
	}

	ret = lv1_write_virtual_uart(DISPMGR_VUART_PORT, vuart_lpar_addr, len, &nwritten);
	if (ret < 0) goto leave;

	if(nwritten>len) nwritten=len;

	ret=nwritten;

leave:
	{lv1_undocumented_function_115(vuart_lpar_addr);}
	{lv1_release_memory(vuart_lpar_addr);}
	remove_new_poke();
	return ret;
}


int auth_drive(u64 arg, u8 mode)
{

	int ret;
	u64 vuart_lpar_addr, muid, nwritten;
	install_new_poke();
	ret = lv1_allocate_memory(4096, 0x0C, 0, &vuart_lpar_addr, &muid);
 	if (ret) {remove_new_poke(); return (ret);}

	ret =  mm_map_lpar_memory_region(vuart_lpar_addr, HV_BASE, HV_SIZE, HV_PAGE_SIZE, 0);
 	if (ret) { {lv1_release_memory(vuart_lpar_addr);} remove_new_poke(); return (ret);}

	uint64_t laid, paid;
	u16 len;

	laid = LAID;
	paid = PAID;

	struct ps3dm_sm_drive_auth drive_auth;
	u8*p=(u8*)&drive_auth;
	memset(&drive_auth, 0, sizeof(drive_auth));

	ps3dm_init_header(&drive_auth.dm_hdr, 1, PS3DM_FID_SM,
	    sizeof(drive_auth) - sizeof(struct ps3dm_header),
	    sizeof(drive_auth) - sizeof(struct ps3dm_header));
	if(!mode)
		ps3dm_init_ss_header(&drive_auth.ss_hdr, PS3DM_PID_SM_DRIVE_AUTH, laid, paid);
	else
		ps3dm_init_ss_header(&drive_auth.ss_hdr, PS3DM_PID_SM_DRIVE_CTRL, laid, paid);

	drive_auth.arg = arg;

	len = sizeof(drive_auth);

	for(u16 n = 0; n < len; n += 8)
	{
		static u64 value;
		memcpy(&value, &p[n], 8);
		lv2_poke(HV_BASE + (u64) n, value);
		__asm__("sync");
		value =  Lv2Syscall1(6, 0x8000000000000000ULL);
	}

	ret = lv1_write_virtual_uart(DISPMGR_VUART_PORT, vuart_lpar_addr, len, &nwritten);
	if (ret < 0) goto leave;

	if(nwritten>len) nwritten=len;

	ret=nwritten;

leave:
	{lv1_undocumented_function_115(vuart_lpar_addr);}
	{lv1_release_memory(vuart_lpar_addr);}
	remove_new_poke();
	return ret;
}
*/