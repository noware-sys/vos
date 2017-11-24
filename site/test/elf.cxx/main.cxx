#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv [])
{
	int fd;
	void *addr1, *addr2;
	unsigned char buff1 [0x186b8f], buff2 [0x8228/* File size*/];
	char addr_str [8 + 1];
	char jmp_str [8 + 4 + 1];
	
	if (argc < 2)
	{
		fprintf (stderr, "%s <file>\n", argv [0]);
		
		return EXIT_FAILURE;
	}
	
	// Open the file.
	fd = open (argv [1], O_RDONLY);
	// Verify that it is open.
	assert (fd > 0);
	
	// Read the first LOAD directive.
	assert (read (fd, buff1, 0x186b8f) == 0x186b8f);
	
	//// Reset the pointer to the beginning of the file.
	//assert (lseek (fd, 0x0, SEEK_SET) == 0x0);
	// Set the pointer to the second LOAD directive.
	assert (lseek (fd, 0x187a80, SEEK_SET) == 0x187a80);
	assert (read (fd, buff2, 0x8228) == 0x8228);
	
	// Close the file.
	assert (close (fd) == 0);
	
	// Reserve/Allocate a RAM region from the OS.
	//addr1 = mmap (0x400000, 0x186b8f, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0);
	//addr2 = mmap (0x787a80, 0xc808/* Memory size*/, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0);
	addr1 = mmap (NULL, 0x186b8f, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0);
	addr2 = mmap (NULL, 0xc808/* Memory size*/, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0);
	//addr = mmap (NULL, 0x18edb7, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0);
	assert (addr1 != MAP_FAILED);
	assert (addr2 != MAP_FAILED);
	//assert (addr != MAP_FAILED);
	//assert (addr1 == 0x400000);
	//assert (addr2 == 0x787a80);
	
	printf ("addr1[%x]\n", addr1);
	printf ("addr2[%x]\n", addr2);
	
	// Copy the contents of the buffers into the newly allocated memory.
	//memcpy (0x400000/* Destination*/, buff1/* Source*/, 0x186b8f/* Size (bytes)*/);
	memcpy (addr1/* Destination*/, buff1/* Source*/, 0x186b8f/* Size (bytes)*/);
	memcpy (addr2, buff2, 0x8228);
//	memcpy (addr + 0x186b8f, buff2, 0x8228);
	
	
	// Jump to the entry point.
	//asm ("ldr r0, =0x400d70");
	//asm ("blx r0");
	//asm ("movl $0x400d70, .");
	//asm ("jmp 0x400d70");
	
	/*
	snprintf (addr_str, 9, "0x%x", addr + 0x400d70);
	printf ("addr[0x%x] + 0x%x = addr_str[%s]\n", addr, 0x400d70, addr_str);
	
	strcpy (jmp_str, "jmp ");
	strcat (jmp_str, addr_str);
	
	printf ("jmp_str[%s]\n", jmp_str);
	asm (jmp_str);
	*/
	
	return EXIT_SUCCESS;
}
