
#include "Memory.h"

Memory::Memory() 
{
	pid = getpid();	
}

Memory::Memory(pid_t _pid)
{
	pid = _pid;
}

Memory::~Memory()
{
	delete this->buffer;
}

char* Memory::GetBuffer()
{
	return this->buffer;
}

bool Memory::Read(size_t address, size_t size)
{
	if (size == 0)
		return false;
	if (this->pid == 0)
		return false;

	struct iovec localSpace[1] {0};
	struct iovec remoteSpace[1] {0};
	
	this->buffer = new char[size];
	localSpace[1].iov_base = this->buffer;
	localSpace[1].iov_len = size;

	remoteSpace[1].iov_base = (void*)address;
	remoteSpace[1].iov_len = size;

	ssize_t sSize = process_vm_readv(this->pid, localSpace, 1, remoteSpace, 1, 0);

	if(sSize == 0)
		return false;
	
	if (sSize == (ssize_t)size)
		return true;

	return false;
}

bool Memory::Write(size_t address, void *buf, size_t size)
{
	return false;	
}
