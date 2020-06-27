#pragma once
#ifndef WAIL32_H
#define WAIL32_H

#ifdef WAIL32DETOUR_EXPORTS
#define Ext extern "C" __declspec(dllexport) 
#else
#define Ext extern "C" __declspec(dllimport) 
#endif

/*-----------------------------------------------------------------------------------------------------
Custom Function Pointers to Game Address Locations
-------------------------------------------------------------------------------------------------------*/
typedef int(WINAPI* pFILE_read)(LPCSTR, LPVOID);
typedef int(WINAPI* pFILE_size)(LPCVOID);
typedef int(WINAPI* pMEM_alloc_lock)(SIZE_T);
typedef int(WINAPI* pMEM_free_lock)(LPCVOID);
typedef int(WINAPI* pAIL_startup)(void);
typedef int(WINAPI* pAIL_shutdown)(void);
typedef int(WINAPI* pAIL_set_preference)(int, int);
typedef int(WINAPI* pAIL_register_timer)(int);
typedef int(WINAPI* pAIL_set_timer_user)(int, int);
typedef int(WINAPI* pAIL_set_timer_period)(int, int);
typedef int(WINAPI* pAIL_start_timer)(int);
typedef int(WINAPI* pAIL_waveOutOpen)(int, int, int, int);
typedef int(WINAPI* pAIL_last_error)(void);
typedef int(WINAPI* pAIL_allocate_sample_handle)(int);
typedef int(WINAPI* pAIL_sample_status)(int);
typedef int(WINAPI* pAIL_init_sample)(int);
typedef int(WINAPI* pAIL_set_sample_file)(int, int, int);
typedef int(WINAPI* pAIL_set_sample_volume)(int, int);
typedef int(WINAPI* pAIL_set_sample_pan)(int, int);
typedef int(WINAPI* pAIL_set_sample_loop_count)(int, int);
typedef int(WINAPI* pAIL_set_sample_playback_rate)(int, int);
typedef int(WINAPI* pAIL_set_sample_type)(int, int, int);
typedef int(WINAPI* pAIL_set_sample_address)(int, int, int);
typedef int(WINAPI* pAIL_start_sample)(int);
typedef int(WINAPI* pAIL_stop_sample)(int);
typedef int(WINAPI* pAIL_resume_sample)(int);
typedef int(WINAPI* pAIL_end_sample)(int);
typedef int(WINAPI* pAIL_serve)(void);
typedef int(WINAPI* pAIL_sample_buffer_ready)(int);
typedef int(WINAPI* pAIL_load_sample_buffer)(int, int, int, int);
typedef int(WINAPI* pAIL_minimum_sample_buffer_size)(int, int, int);
typedef pAIL_minimum_sample_buffer_size pAIL_midiOutOpen;
typedef pAIL_end_sample pAIL_midiOutClose;
typedef pAIL_set_sample_playback_rate pAIL_register_EOS_callback;
typedef pAIL_end_sample pAIL_waveOutClose;
typedef pAIL_end_sample pAIL_release_sample_handle;
typedef pAIL_set_sample_playback_rate pAIL_register_EOB_callback;
typedef pAIL_minimum_sample_buffer_size pAIL_set_sample_user_data;
typedef pAIL_set_sample_playback_rate pAIL_sample_user_data;
typedef void (WINAPI* pWriteToFile)(LPCSTR);
typedef void (*pFixPath)(std::string&);

//Ext HMODULE LoadWail(void);
Ext int WINAPI FILE_read(LPCSTR, LPVOID); //'_FILE_read@8'
Ext int WINAPI FILE_size(LPCVOID); //'_FILE_size@4'
Ext int WINAPI MEM_alloc_lock(SIZE_T); //'_MEM_alloc_lock@4'
Ext int WINAPI MEM_free_lock(LPCVOID); //'_MEM_free_lock@4'
Ext int WINAPI AIL_startup(void); //'_AIL_startup@0'
Ext int WINAPI AIL_shutdown(void); //'_AIL_shutdown@0'
Ext int WINAPI AIL_set_preference(int, int); //'_AIL_set_preference@8'
Ext int __cdecl AIL_register_timer(int); //'AIL_register_timer@4'
Ext int __cdecl AIL_set_timer_user(int, int); //'AIL_set_timer_user@8'
Ext int __cdecl AIL_set_timer_period(int, int); //'AIL_set_timer_period@8'
Ext int __cdecl AIL_start_timer(int); //'AIL_start_timer@4'
Ext int WINAPI AIL_waveOutOpen(int, int, int, int); //'_AIL_waveOutOpen@16'
Ext int WINAPI AIL_last_error(void); //'_AIL_last_error@0'
Ext int WINAPI AIL_allocate_sample_handle(int); //'_AIL_allocate_sample_handle@4'
Ext int WINAPI AIL_sample_status(int); //'_AIL_sample_status@4'
Ext int WINAPI AIL_init_sample(int); //'_AIL_init_sample@4'
Ext int WINAPI AIL_set_sample_file(int, int, int); //'_AIL_set_sample_file@12'
Ext int WINAPI AIL_set_sample_volume(int, int); //'_AIL_set_sample_volume@8'
Ext int WINAPI AIL_set_sample_pan(int, int); //'_AIL_set_sample_pan@8',0
Ext int WINAPI AIL_set_sample_loop_count(int, int); //'_AIL_set_sample_loop_count@8',0
Ext int WINAPI AIL_set_sample_playback_rate(int, int); //'_AIL_set_sample_playback_rate@8',0
Ext int WINAPI AIL_set_sample_type(int, int, int); //'_AIL_set_sample_type@12'
Ext int WINAPI AIL_set_sample_address(int, int, int); //'_AIL_set_sample_address@12'
Ext int WINAPI AIL_start_sample(int); //'_AIL_start_sample@4'
Ext int WINAPI AIL_stop_sample(int); //'_AIL_stop_sample@4'
Ext int WINAPI AIL_resume_sample(int); //'_AIL_resume_sample@4'
Ext int WINAPI AIL_end_sample(int); //'_AIL_end_sample@4'
Ext int WINAPI AIL_serve(void); //'_AIL_serve@0'
Ext int WINAPI AIL_sample_buffer_ready(int); //'_AIL_sample_buffer_ready@4'
Ext int WINAPI AIL_load_sample_buffer(int, int, int, int); //'_AIL_load_sample_buffer@16'
Ext int WINAPI AIL_minimum_sample_buffer_size(int, int, int); //'_AIL_minimum_sample_buffer_size@12'
Ext int WINAPI AIL_midiOutOpen(int, int, int); //_AIL_midiOutOpen@12
Ext int WINAPI AIL_midiOutClose(int); //_AIL_midiOutClose@4
Ext int WINAPI AIL_register_EOS_callback(int, int);
Ext int WINAPI AIL_waveOutClose(int);
Ext int WINAPI AIL_release_sample_handle(int);
Ext int WINAPI AIL_register_EOB_callback(int, int);
Ext int WINAPI AIL_set_sample_user_data(int, int, int);
Ext int WINAPI AIL_sample_user_data(int, int);

#endif