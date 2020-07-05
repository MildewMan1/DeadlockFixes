#include "pch.h"
#include "WAIL32.h"

HMODULE hMod_MSS32 = LoadLibraryA("MSS32.DLL");

Ext int WINAPI FILE_read(LPCSTR a1, LPVOID a2) //'_FILE_read@8'
{
	pFILE_read oFILE_read = (pFILE_read)GetProcAddress(hMod_MSS32, "_AIL_file_read@8");
	if (oFILE_read)
	{
		int result = oFILE_read(a1, a2);
		return result;
	}
	return -1;
}

Ext int WINAPI FILE_size(LPCVOID a1) //'_FILE_size@4'
{
	pFILE_size oFILE_size = (pFILE_size)GetProcAddress(hMod_MSS32, "_AIL_file_size@4");
	if (oFILE_size)
	{
		return oFILE_size(a1);
	}
	return -1;
}

Ext int WINAPI MEM_alloc_lock(SIZE_T a1) //'_MEM_alloc_lock@4'
{
	pMEM_alloc_lock oMEM_alloc_lock = (pMEM_alloc_lock)GetProcAddress(hMod_MSS32, "_AIL_mem_alloc_lock@4");
	if (oMEM_alloc_lock)
	{
		return oMEM_alloc_lock(a1);
	}
	return -1;
}

Ext int WINAPI MEM_free_lock(LPCVOID a1) //'_MEM_free_lock@4'
{
	pMEM_free_lock oMEM_free_lock = (pMEM_free_lock)GetProcAddress(hMod_MSS32, "_AIL_mem_free_lock@4");
	if (oMEM_free_lock)
	{
		return oMEM_free_lock(a1);
	}
	return -1;
}

Ext int WINAPI AIL_startup(void) //'_AIL_startup@0'
{
	pAIL_startup oAIL_startup = GetProcAddress(hMod_MSS32, "_AIL_startup@0");
	if (oAIL_startup)
	{
		return oAIL_startup();
	}
	return -1;
}

Ext int WINAPI AIL_shutdown(void) //'_AIL_shutdown@0'
{
	pAIL_shutdown oAIL_shutdown = (pAIL_shutdown)GetProcAddress(hMod_MSS32, "_AIL_shutdown@0");
	if (oAIL_shutdown)
	{
		return oAIL_shutdown();
	}
	return -1;
}

Ext int WINAPI AIL_set_preference(int a1, int a2) //'_AIL_set_preference@8'
{
	pAIL_set_preference oAIL_set_preference = (pAIL_set_preference)GetProcAddress(hMod_MSS32, "_AIL_set_preference@8");
	if (oAIL_set_preference)
	{
		return oAIL_set_preference(a1, a2);
	}
	return -1;
}

Ext int __cdecl AIL_register_timer(int a1) //'AIL_register_timer@4'
{
	pAIL_register_timer oAIL_register_timer = (pAIL_register_timer)GetProcAddress(hMod_MSS32, "_AIL_register_timer@4");
	if (oAIL_register_timer)
	{
		int result = oAIL_register_timer(a1);
		return result;
	}
	return -1;
}

Ext int __cdecl AIL_set_timer_user(int a1, int a2) //'AIL_set_timer_user@8'
{
	pAIL_set_timer_user oAIL_set_timer_user = (pAIL_set_timer_user)GetProcAddress(hMod_MSS32, "_AIL_set_timer_user@8");
	if (oAIL_set_timer_user)
	{
		int result = oAIL_set_timer_user(a1, a2);
		return result;
	}
	return -1;
}

Ext int __cdecl AIL_set_timer_period(int a1, int a2) //'AIL_set_timer_period@8'
{
	pAIL_set_timer_period oAIL_set_timer_period = (pAIL_set_timer_period)GetProcAddress(hMod_MSS32, "_AIL_set_timer_period@8");
	if (oAIL_set_timer_period)
	{
		int result = oAIL_set_timer_period(a1, a2);
		return result;
	}
	return -1;
}

Ext int __cdecl AIL_start_timer(int a1) //'AIL_start_timer@4'
{
	pAIL_start_timer oAIL_start_timer = (pAIL_start_timer)GetProcAddress(hMod_MSS32, "_AIL_start_timer@4");
	if (oAIL_start_timer)
	{
		int result = oAIL_start_timer(a1);
		return result;
	}
	return -1;
}

Ext int WINAPI AIL_waveOutOpen(int a1, int a2, int a3, int a4) //'_AIL_waveOutOpen@16'
{
	pAIL_waveOutOpen oAIL_waveOutOpen = (pAIL_waveOutOpen)GetProcAddress(hMod_MSS32, "_AIL_waveOutOpen@16");
	if (oAIL_waveOutOpen)
	{
		return oAIL_waveOutOpen(a1, a2, a3, a4);
	}
	return -1;
}

Ext int WINAPI AIL_last_error(void) //'_AIL_last_error@0'
{
	pAIL_last_error oAIL_last_error = (pAIL_last_error)GetProcAddress(hMod_MSS32, "_AIL_last_error@0");
	if (oAIL_last_error)
	{
		return oAIL_last_error();
	}
	return -1;
}

Ext int WINAPI AIL_allocate_sample_handle(int a1) //'_AIL_allocate_sample_handle@4'
{
	pAIL_allocate_sample_handle oAIL_allocate_sample_handle = (pAIL_allocate_sample_handle)GetProcAddress(hMod_MSS32, "_AIL_allocate_sample_handle@4");
	if (oAIL_allocate_sample_handle)
	{
		return oAIL_allocate_sample_handle(a1);
	}
	return -1;
}

Ext int WINAPI AIL_sample_status(int a1) //'_AIL_sample_status@4'
{
	pAIL_sample_status oAIL_sample_status = (pAIL_sample_status)GetProcAddress(hMod_MSS32, "_AIL_sample_status@4");
	if (oAIL_sample_status)
	{
		return oAIL_sample_status(a1);
	}
	return -1;
}

Ext int WINAPI AIL_init_sample(int a1) //'_AIL_init_sample@4'
{
	pAIL_init_sample oAIL_init_sample = (pAIL_init_sample)GetProcAddress(hMod_MSS32, "_AIL_init_sample@4");
	if (oAIL_init_sample)
	{
		return oAIL_init_sample(a1);
	}
	return -1;
}

Ext int WINAPI AIL_set_sample_file(int a1, int a2, int a3) //'_AIL_set_sample_file@12'
{
	pAIL_set_sample_file oAIL_set_sample_file = (pAIL_set_sample_file)GetProcAddress(hMod_MSS32, "_AIL_set_sample_file@12");
	if (oAIL_set_sample_file)
	{
		return oAIL_set_sample_file(a1, a2, a3);
	}
	return -1;
}

Ext int WINAPI AIL_set_sample_volume(int a1, int a2) //'_AIL_set_sample_volume@8'
{
	pAIL_set_sample_volume oAIL_set_sample_volume = (pAIL_set_sample_volume)GetProcAddress(hMod_MSS32, "_AIL_set_sample_volume@8");
	if (oAIL_set_sample_volume)
	{
		return oAIL_set_sample_volume(a1, a2);
	}
	return -1;
}

Ext int WINAPI AIL_set_sample_pan(int a1, int a2) //'_AIL_set_sample_pan@8',0
{
	pAIL_set_sample_pan oAIL_set_sample_pan = (pAIL_set_sample_pan)GetProcAddress(hMod_MSS32, "_AIL_set_sample_pan@8");
	if (oAIL_set_sample_pan)
	{
		return oAIL_set_sample_pan(a1, a2);
	}
	return -1;
}

Ext int WINAPI AIL_set_sample_loop_count(int a1, int a2) //'_AIL_set_sample_loop_count@8',0
{
	pAIL_set_sample_loop_count oAIL_set_sample_loop_count = (pAIL_set_sample_loop_count)GetProcAddress(hMod_MSS32, "_AIL_set_sample_loop_count@8");
	if (oAIL_set_sample_loop_count)
	{
		return oAIL_set_sample_loop_count(a1, a2);
	}
	return -1;
}

Ext int WINAPI AIL_set_sample_playback_rate(int a1, int a2) //'_AIL_set_sample_playback_rate@8',0
{
	pAIL_set_sample_playback_rate oAIL_set_sample_playback_rate = (pAIL_set_sample_playback_rate)GetProcAddress(hMod_MSS32, "_AIL_set_sample_playback_rate@8");
	if (oAIL_set_sample_playback_rate)
	{
		return oAIL_set_sample_playback_rate(a1, a2);
	}
	return -1;
}

Ext int WINAPI AIL_set_sample_type(int a1, int a2, int a3) //'_AIL_set_sample_type@12'
{
	pAIL_set_sample_type oAIL_set_sample_type = (pAIL_set_sample_type)GetProcAddress(hMod_MSS32, "_AIL_set_sample_type@12");
	if (oAIL_set_sample_type)
	{
		return oAIL_set_sample_type(a1, a2, a3);
	}
	return -1;
}

Ext int WINAPI AIL_set_sample_address(int a1, int a2, int a3) //'_AIL_set_sample_address@12'
{
	pAIL_set_sample_address oAIL_set_sample_address = (pAIL_set_sample_address)GetProcAddress(hMod_MSS32, "_AIL_set_sample_address@12");
	if (oAIL_set_sample_address)
	{
		return oAIL_set_sample_address(a1, a2, a3);
	}
	return -1;
}

Ext int WINAPI AIL_start_sample(int a1) //'_AIL_start_sample@4'
{
	pAIL_start_sample oAIL_start_sample = (pAIL_start_sample)GetProcAddress(hMod_MSS32, "_AIL_start_sample@4");
	if (oAIL_start_sample)
	{
		return oAIL_start_sample(a1);
	}
	return -1;
}

Ext int WINAPI AIL_stop_sample(int a1) //'_AIL_stop_sample@4'
{
	pAIL_stop_sample oAIL_stop_sample = (pAIL_stop_sample)GetProcAddress(hMod_MSS32, "_AIL_stop_sample@4");
	if (oAIL_stop_sample)
	{
		return oAIL_stop_sample(a1);
	}
	return -1;
}

Ext int WINAPI AIL_resume_sample(int a1) //'_AIL_resume_sample@4'
{
	pAIL_resume_sample oAIL_resume_sample = (pAIL_resume_sample)GetProcAddress(hMod_MSS32, "_AIL_resume_sample@4");
	if (oAIL_resume_sample)
	{
		return oAIL_resume_sample(a1);
	}
	return -1;
}

Ext int WINAPI AIL_end_sample(int a1) //'_AIL_end_sample@4'
{
	pAIL_end_sample oAIL_end_sample = (pAIL_end_sample)GetProcAddress(hMod_MSS32, "_AIL_end_sample@4");
	if (oAIL_end_sample)
	{
		return oAIL_end_sample(a1);
	}
	return -1;
}

Ext int WINAPI AIL_serve(void) //'_AIL_serve@0'
{
	pAIL_serve oAIL_serve = (pAIL_serve)GetProcAddress(hMod_MSS32, "_AIL_serve@0");
	if (oAIL_serve)
	{
		return oAIL_serve();
	}
	return -1;
}

Ext int WINAPI AIL_sample_buffer_ready(int a1) //'_AIL_sample_buffer_ready@4'
{
	pAIL_sample_buffer_ready oAIL_sample_buffer_ready = (pAIL_sample_buffer_ready)GetProcAddress(hMod_MSS32, "_AIL_sample_buffer_ready@4");
	if (oAIL_sample_buffer_ready)
	{
		return oAIL_sample_buffer_ready(a1);
	}
	return -1;
}

Ext int WINAPI AIL_load_sample_buffer(int a1, int a2, int a3, int a4) //'_AIL_load_sample_buffer@16'
{
	pAIL_load_sample_buffer oAIL_load_sample_buffer = (pAIL_load_sample_buffer)GetProcAddress(hMod_MSS32, "_AIL_load_sample_buffer@16");
	if (oAIL_load_sample_buffer)
	{
		return oAIL_load_sample_buffer(a1, a2, a3, a4);
	}
	return -1;
}

Ext int WINAPI AIL_minimum_sample_buffer_size(int a1, int a2, int a3) //'_AIL_minimum_sample_buffer_size@12'
{
	pAIL_minimum_sample_buffer_size oAIL_minimum_sample_buffer_size = (pAIL_minimum_sample_buffer_size)GetProcAddress(hMod_MSS32, "_AIL_minimum_sample_buffer_size@12");
	if (oAIL_minimum_sample_buffer_size)
	{
		return oAIL_minimum_sample_buffer_size(a1, a2, a3);
	}
	return -1;
}

Ext int WINAPI AIL_midiOutOpen(int a1, int a2, int a3)
{
	pAIL_minimum_sample_buffer_size oAIL_minimum_sample_buffer_size = (pAIL_minimum_sample_buffer_size)GetProcAddress(hMod_MSS32, "_AIL_minimum_sample_buffer_size@12");
	if (oAIL_minimum_sample_buffer_size)
	{
		return oAIL_minimum_sample_buffer_size(a1, a2, a3);
	}
	return -1;
}

Ext int WINAPI AIL_midiOutClose(int a1)
{
	pAIL_midiOutClose oAIL_midiOutClose = (pAIL_midiOutClose)GetProcAddress(hMod_MSS32, "_AIL_midiOutClose@4");
	if (oAIL_midiOutClose)
	{
		return oAIL_midiOutClose(a1);
	}
	return -1;
}

Ext int WINAPI AIL_register_EOS_callback(int a1, int a2)
{
	pAIL_register_EOS_callback oAIL_register_EOS_callback = (pAIL_register_EOS_callback)GetProcAddress(hMod_MSS32, "_AIL_register_EOS_callback@8");
	if (oAIL_register_EOS_callback)
	{
		return oAIL_register_EOS_callback(a1, a2);
	}
	return -1;
}

Ext int WINAPI AIL_waveOutClose(int a1)
{
	pAIL_waveOutClose oAIL_waveOutClose = (pAIL_waveOutClose)GetProcAddress(hMod_MSS32, "_AIL_waveOutClose@4");
	if (oAIL_waveOutClose)
	{
		return oAIL_waveOutClose(a1);
	}
	return -1;
}

Ext int WINAPI AIL_release_sample_handle(int a1)
{
	pAIL_release_sample_handle oAIL_release_sample_handle = (pAIL_release_sample_handle)GetProcAddress(hMod_MSS32, "_AIL_release_sample_handlee@4");
	if (oAIL_release_sample_handle)
	{
		return oAIL_release_sample_handle(a1);
	}
	return -1;
}

Ext int WINAPI AIL_register_EOB_callback(int a1, int a2)
{
	pAIL_register_EOB_callback oAIL_register_EOB_callback = (pAIL_register_EOB_callback)GetProcAddress(hMod_MSS32, "_AIL_register_EOB_callback@8");
	if (oAIL_register_EOB_callback)
	{
		return oAIL_register_EOB_callback(a1, a2);
	}
	return -1;
}

Ext int WINAPI AIL_set_sample_user_data(int a1, int a2, int a3)
{
	pAIL_set_sample_user_data oAIL_set_sample_user_data = (pAIL_set_sample_user_data)GetProcAddress(hMod_MSS32, "_AIL_set_sample_user_data@12");
	if (oAIL_set_sample_user_data)
	{
		return oAIL_set_sample_user_data(a1, a2, a3);
	}
	return -1;
}

Ext int WINAPI AIL_sample_user_data(int a1, int a2)
{
	pAIL_sample_user_data oAIL_sample_user_data = (pAIL_sample_user_data)GetProcAddress(hMod_MSS32, "_AIL_sample_user_data@8");
	if (oAIL_sample_user_data)
	{
		return oAIL_sample_user_data(a1, a2);
	}
	return -1;
}