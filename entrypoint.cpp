#ifndef entrypoint_cpp
#define entrypoint_cpp

//header
#include <dependencies/kernel/memory.h>
#include <core/cheat/render.h>
#include <core/cheat/loops/cache.h>
#include <iostream>
#include <dependencies/kernel/noxim.h>

auto execute_main( ) -> void {

	mem::get_driver();

	MessageBoxA(0, noXim("Open Fortnite then press OK in lobby ONLY !").decrypt(), noXim("").decrypt(), 0);

	mem::process_id = mem::get_process(noXim("FortniteClient-Win64-Shipping.exe").decrypt()); // Note: depends if your noXim supports wide strings

	getcr3 = mem::CR3();

	Base = mem::find_base_address();

	printf(noXim("Game Base | 0x%llx\n").decrypt(), Base);
	printf(noXim("Game CR3 | 0x%llx\n").decrypt(), getcr3);

	overlay.initialize_overlay( );
	overlay.initialize_imgui( );

	std::thread(cache_thread).detach();
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)overlay.render_loop(), NULL, 0, NULL);

}

int main( ) {
	execute_main( );

	return 0;
}

#endif