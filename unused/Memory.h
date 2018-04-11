#ifndef MEMORY_HEADER
#define MEMORY_HEADER

#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>


class Memory
{
public: 
	Memory();
	Memory(pid_t _pid);
	~Memory();

	char* GetBuffer();

	bool Read(size_t address, size_t size);
	bool Write(size_t address, void *buf, size_t size);
private: 
	pid_t pid;
	char *buffer;
};
#endif
