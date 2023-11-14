#include "hsh.h"

/**
 * custom_getline - Reads a line from a file descriptor.
 * @lineptr: Pointer to the buffer that will contain the line.
 * @n: Pointer to the size of the buffer.
 * @fd: File descriptor to read from.
 *
 * Description: This function reads an entire line from a file descriptor.
 *
 * Return: The number of characters read.
 */

ssize_t custom_getline(char **lineptr, size_t *n, int fd) {
    static char buffer[BUFFER_SIZE];
    static int buffer_offset = 0;
    static int buffer_length = 0;
    ssize_t total_length = 0;
    int line_terminated = 0;

    if (!lineptr || !n) {
        return -1;
    }

    *lineptr = NULL;
    *n = 0;

    while (!line_terminated) {
        if (buffer_offset >= buffer_length) {
            buffer_length = read(fd, buffer, BUFFER_SIZE);
            if (buffer_length <= 0) {
                if (total_length == 0) {
                    return buffer_length;
		}
                break;
	    }
            buffer_offset = 0;
	}

        for (; buffer_offset < buffer_length && !line_terminated; buffer_offset++) {
            char c = buffer[buffer_offset];

            if ((size_t)total_length + 1 >= *n) {
                *n += BUFFER_SIZE;
                *lineptr = realloc(*lineptr, *n);
                if (!*lineptr) {
                    return -1;
		}
	    }

            (*lineptr)[total_length++] = c;

            if (c == '\n') {
                line_terminated = 1;
	    }
	}
    }

    if (*lineptr) {
        (*lineptr)[total_length] = '\0';
    }

    return total_length;
}
