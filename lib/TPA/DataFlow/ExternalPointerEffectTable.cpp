#include "TPA/DataFlow/ExternalPointerEffectTable.h"

using namespace llvm;

namespace tpa
{

void ExternalPointerEffectTable::setUpInitialTable()
{
	table = {
		{"_IO_getc", PointerEffect::NoEffect},
		{"_IO_putc", PointerEffect::NoEffect},
		{"_exit", PointerEffect::NoEffect},
		{"_setjmp", PointerEffect::NoEffect},
		{"__assert_fail", PointerEffect::NoEffect},
		{"__dn_expand", PointerEffect::NoEffect},
		{"__dn_skipname", PointerEffect::NoEffect},
		{"__isoc99_fscanf", PointerEffect::NoEffect},
		{"__isoc99_scanf", PointerEffect::NoEffect},
		{"__isoc99_sscanf", PointerEffect::NoEffect},
		{"__res_init", PointerEffect::NoEffect},
		{"__res_querydomain", PointerEffect::NoEffect},
		{"__res_search", PointerEffect::NoEffect},
		{"__sigsetjmp", PointerEffect::NoEffect},
		{"abs", PointerEffect::NoEffect},
		{"accept", PointerEffect::NoEffect},
		{"access", PointerEffect::NoEffect},
		{"alarm", PointerEffect::NoEffect},
		{"asprintf", PointerEffect::NoEffect},
		{"atexit", PointerEffect::NoEffect},
		{"atof", PointerEffect::NoEffect},
		{"atoi", PointerEffect::NoEffect},
		{"atol", PointerEffect::NoEffect},
		{"bind", PointerEffect::NoEffect},
		{"btowc", PointerEffect::NoEffect},
		{"cfgetospeed", PointerEffect::NoEffect},
		{"cfree", PointerEffect::NoEffect},
		{"cfsetispeed", PointerEffect::NoEffect},
		{"cfsetospeed", PointerEffect::NoEffect},
		{"chdir", PointerEffect::NoEffect},
		{"chmod", PointerEffect::NoEffect},
		{"chown", PointerEffect::NoEffect},
		{"chroot", PointerEffect::NoEffect},
		{"clearerr", PointerEffect::NoEffect},
		{"clearok", PointerEffect::NoEffect},
		{"clock", PointerEffect::NoEffect},
		{"close", PointerEffect::NoEffect},
		{"closedir", PointerEffect::NoEffect},
		{"closelog", PointerEffect::NoEffect},
		{"confstr", PointerEffect::NoEffect},
		{"connect", PointerEffect::NoEffect},
		{"creat", PointerEffect::NoEffect},
		{"creat64", PointerEffect::NoEffect},
		{"difftime", PointerEffect::NoEffect},
		{"dladdr", PointerEffect::NoEffect},
		{"dlclose", PointerEffect::NoEffect},
		{"dup", PointerEffect::NoEffect},
		{"dup2", PointerEffect::NoEffect},
		{"endpwent", PointerEffect::NoEffect},
		{"execl", PointerEffect::NoEffect},
		{"execle", PointerEffect::NoEffect},
		{"execlp", PointerEffect::NoEffect},
		{"execv", PointerEffect::NoEffect},
		{"execve", PointerEffect::NoEffect},
		{"execvp", PointerEffect::NoEffect},
		{"exp", PointerEffect::NoEffect},
		{"exp2", PointerEffect::NoEffect},
		{"exp10", PointerEffect::NoEffect},
		{"fabsf", PointerEffect::NoEffect},
		{"fchmod", PointerEffect::NoEffect},
		{"fchown", PointerEffect::NoEffect},
		{"fclose", PointerEffect::NoEffect},
		{"fcntl", PointerEffect::NoEffect},
		{"feof", PointerEffect::NoEffect},
		{"ferror", PointerEffect::NoEffect},
		{"fflush", PointerEffect::NoEffect},
		{"fgetc", PointerEffect::NoEffect},
		{"fgetpos", PointerEffect::NoEffect},
		{"fileno", PointerEffect::NoEffect},
		{"flockfile", PointerEffect::NoEffect},
		{"floorf", PointerEffect::NoEffect},
		{"fnmatch", PointerEffect::NoEffect},
		{"fork", PointerEffect::NoEffect},
		{"forkpty", PointerEffect::NoEffect},
		{"fprintf", PointerEffect::NoEffect},
		{"fputc", PointerEffect::NoEffect},
		{"fputs", PointerEffect::NoEffect},
		{"fputs_unlocked", PointerEffect::NoEffect},
		{"fread", PointerEffect::NoEffect},
		{"free", PointerEffect::NoEffect},
		{"freeaddrinfo", PointerEffect::NoEffect},
		{"frexp", PointerEffect::NoEffect},
		{"fscanf", PointerEffect::NoEffect},
		{"fseek", PointerEffect::NoEffect},
		{"fseeko", PointerEffect::NoEffect},
		{"fseeko64", PointerEffect::NoEffect},
		{"fsetpos", PointerEffect::NoEffect},
		{"fstat", PointerEffect::NoEffect},
		{"fstat64", PointerEffect::NoEffect},
		{"fstatfs", PointerEffect::NoEffect},
		{"fsync", PointerEffect::NoEffect},
		{"fpathconf", PointerEffect::NoEffect},
		{"ftell", PointerEffect::NoEffect},
		{"ftello", PointerEffect::NoEffect},
		{"ftok", PointerEffect::NoEffect},
		{"ftruncate", PointerEffect::NoEffect},
		{"funlockfile", PointerEffect::NoEffect},
		{"fwrite", PointerEffect::NoEffect},
		{"getaddrinfo", PointerEffect::NoEffect},
		{"getchar", PointerEffect::NoEffect},
		{"getc_unlocked", PointerEffect::NoEffect},
		{"getdtablesize", PointerEffect::NoEffect},
		{"getegid", PointerEffect::NoEffect},
		{"geteuid", PointerEffect::NoEffect},
		{"getgid", PointerEffect::NoEffect},
		{"getgroups", PointerEffect::NoEffect},
		{"gethostname", PointerEffect::NoEffect},
		{"getloadavg", PointerEffect::NoEffect},
		{"getopt", PointerEffect::NoEffect},
		{"getopt_long", PointerEffect::NoEffect},
		{"getopt_long_only", PointerEffect::NoEffect},
		{"getpeername", PointerEffect::NoEffect},
		{"getpgid", PointerEffect::NoEffect},
		{"getpid", PointerEffect::NoEffect},
		{"getppid", PointerEffect::NoEffect},
		{"getsid", PointerEffect::NoEffect},
		{"getuid", PointerEffect::NoEffect},
		{"getresgid", PointerEffect::NoEffect},
		{"getresuid", PointerEffect::NoEffect},
		{"getrlimit", PointerEffect::NoEffect},
		{"getrlimit64", PointerEffect::NoEffect},
		{"getrusage", PointerEffect::NoEffect},
		{"getsockname", PointerEffect::NoEffect},
		{"getsockopt", PointerEffect::NoEffect},
		{"gettimeofday", PointerEffect::NoEffect},
		{"globfree", PointerEffect::NoEffect},
		{"gnu_dev_major", PointerEffect::NoEffect},
		{"gnu_dev_minor", PointerEffect::NoEffect},
		{"gzclose", PointerEffect::NoEffect},
		{"gzeof", PointerEffect::NoEffect},
		{"gzgetc", PointerEffect::NoEffect},
		{"gzread", PointerEffect::NoEffect},
		{"gzseek", PointerEffect::NoEffect},
		{"gztell", PointerEffect::NoEffect},
		{"gzwrite", PointerEffect::NoEffect},
		{"has_colors", PointerEffect::NoEffect},
		{"htonl", PointerEffect::NoEffect},
		{"htons", PointerEffect::NoEffect},
		{"iconv_close", PointerEffect::NoEffect},
		{"inet_addr", PointerEffect::NoEffect},
		{"inet_aton", PointerEffect::NoEffect},
		{"inet_pton", PointerEffect::NoEffect},
		{"initgroups", PointerEffect::NoEffect},
		// This is a really nasty API. We choose to ignore it now for simplicity
		{"ioctl", PointerEffect::NoEffect},
		{"isalnum", PointerEffect::NoEffect},
		{"isalpha", PointerEffect::NoEffect},
		{"isascii", PointerEffect::NoEffect},
		{"isatty", PointerEffect::NoEffect},
		{"isblank", PointerEffect::NoEffect},
		{"iscntrl", PointerEffect::NoEffect},
		{"isdigit", PointerEffect::NoEffect},
		{"isgraph", PointerEffect::NoEffect},
		{"islower", PointerEffect::NoEffect},
		{"isprint", PointerEffect::NoEffect},
		{"ispunct", PointerEffect::NoEffect},
		{"isspace", PointerEffect::NoEffect},
		{"isupper", PointerEffect::NoEffect},
		{"iswalnum", PointerEffect::NoEffect},
		{"iswalpha", PointerEffect::NoEffect},
		{"iswctype", PointerEffect::NoEffect},
		{"iswdigit", PointerEffect::NoEffect},
		{"iswlower", PointerEffect::NoEffect},
		{"iswspace", PointerEffect::NoEffect},
		{"iswprint", PointerEffect::NoEffect},
		{"iswupper", PointerEffect::NoEffect},
		{"kill", PointerEffect::NoEffect},
		{"lchown", PointerEffect::NoEffect},
		{"ldexp", PointerEffect::NoEffect},
		{"link", PointerEffect::NoEffect},
		{"listen", PointerEffect::NoEffect},
		{"llvm.bswap.i16", PointerEffect::NoEffect},
		{"llvm.bswap.i32", PointerEffect::NoEffect},
		{"llvm.ctlz.i64", PointerEffect::NoEffect},
		{"llvm.dbg.declare", PointerEffect::NoEffect},
		{"llvm.dbg.value", PointerEffect::NoEffect},
		{"llvm.lifetime.start", PointerEffect::NoEffect},
		{"llvm.lifetime.end", PointerEffect::NoEffect},
		{"llvm.stackrestore", PointerEffect::NoEffect},
		{"llvm.trap", PointerEffect::NoEffect},
		{"llvm.umul.with.overflow.i64", PointerEffect::NoEffect},
		{"llvm.va_copy", PointerEffect::NoEffect},
		{"llvm.va_end", PointerEffect::NoEffect},
		{"llvm.va_start", PointerEffect::NoEffect},
		{"log", PointerEffect::NoEffect},
		{"log10", PointerEffect::NoEffect},
		{"longjmp", PointerEffect::NoEffect},
		{"lseek", PointerEffect::NoEffect},
		{"lstat", PointerEffect::NoEffect},
		{"lstat64", PointerEffect::NoEffect},
		{"mblen", PointerEffect::NoEffect},
		{"mbrlen", PointerEffect::NoEffect},
		{"mbrtowc", PointerEffect::NoEffect},
		{"mbtowc", PointerEffect::NoEffect},
		{"memcmp", PointerEffect::NoEffect},
		{"mkdir", PointerEffect::NoEffect},
		{"mknod", PointerEffect::NoEffect},
		{"mkfifo", PointerEffect::NoEffect},
		{"mkstemp", PointerEffect::NoEffect},
		{"mktime", PointerEffect::NoEffect},
		{"modf", PointerEffect::NoEffect},
		{"mprotect", PointerEffect::NoEffect},
		{"munmap", PointerEffect::NoEffect},
		{"nice", PointerEffect::NoEffect},
		{"nanosleep", PointerEffect::NoEffect},
		{"ntohl", PointerEffect::NoEffect},
		{"ntohs", PointerEffect::NoEffect},
		{"open", PointerEffect::NoEffect},
		{"open64", PointerEffect::NoEffect},
		{"openlog", PointerEffect::NoEffect},
		{"openpty", PointerEffect::NoEffect},
		{"pathconf", PointerEffect::NoEffect},
		{"pause", PointerEffect::NoEffect},
		{"pclose", PointerEffect::NoEffect},
		{"perror", PointerEffect::NoEffect},
		{"pipe", PointerEffect::NoEffect},
		{"poll", PointerEffect::NoEffect},
		{"pread64", PointerEffect::NoEffect},
		{"printf", PointerEffect::NoEffect},
		{"pthread_attr_destroy", PointerEffect::NoEffect},
		{"pthread_attr_init", PointerEffect::NoEffect},
		{"pthread_attr_setscope", PointerEffect::NoEffect},
		{"pthread_attr_setstacksize", PointerEffect::NoEffect},
		{"pthread_create", PointerEffect::NoEffect},
		{"pthread_mutex_destroy", PointerEffect::NoEffect},
		{"pthread_mutex_init", PointerEffect::NoEffect},
		{"pthread_mutex_lock", PointerEffect::NoEffect},
		{"pthread_mutex_unlock", PointerEffect::NoEffect},
		{"pthread_mutexattr_destroy", PointerEffect::NoEffect},
		{"pthread_mutexattr_init", PointerEffect::NoEffect},
		{"pthread_mutexattr_settype", PointerEffect::NoEffect},
		{"ptsname", PointerEffect::NoEffect},
		{"putenv", PointerEffect::NoEffect},
		{"puts", PointerEffect::NoEffect},
		{"qsort", PointerEffect::NoEffect},
		{"re_exec", PointerEffect::NoEffect},
		{"re_search", PointerEffect::NoEffect},
		{"read", PointerEffect::NoEffect},
		{"readlink", PointerEffect::NoEffect},
		{"recv", PointerEffect::NoEffect},
		{"recvfrom", PointerEffect::NoEffect},
		{"remove", PointerEffect::NoEffect},
		{"rename", PointerEffect::NoEffect},
		{"rewind", PointerEffect::NoEffect},
		{"rewinddir", PointerEffect::NoEffect},
		{"rmdir", PointerEffect::NoEffect},
		{"rresvport", PointerEffect::NoEffect},
		{"scanf", PointerEffect::NoEffect},
		{"scrollok", PointerEffect::NoEffect},
		{"select", PointerEffect::NoEffect},
		{"sem_destroy", PointerEffect::NoEffect},
		{"sem_init", PointerEffect::NoEffect},
		{"sem_post", PointerEffect::NoEffect},
		{"sem_trywait", PointerEffect::NoEffect},
		{"sem_wait", PointerEffect::NoEffect},
		// Not so sure about it. Don't rely on that
		{"semctl", PointerEffect::NoEffect},
		{"semget", PointerEffect::NoEffect},
		{"semop", PointerEffect::NoEffect},
		{"send", PointerEffect::NoEffect},
		{"sendto", PointerEffect::NoEffect},
		{"setbuf", PointerEffect::NoEffect},
		{"setenv", PointerEffect::NoEffect},
		{"seteuid", PointerEffect::NoEffect},
		{"setgid", PointerEffect::NoEffect},
		{"setgroups", PointerEffect::NoEffect},
		{"setitimer", PointerEffect::NoEffect},
		{"setpwent", PointerEffect::NoEffect},
		{"setregid", PointerEffect::NoEffect},
		{"setreuid", PointerEffect::NoEffect},
		{"setrlimit", PointerEffect::NoEffect},
		{"setsid", PointerEffect::NoEffect},
		{"setsockopt", PointerEffect::NoEffect},
		{"setuid", PointerEffect::NoEffect},
		{"setvbuf", PointerEffect::NoEffect},
		// Not so sure about it
		{"shmctl", PointerEffect::NoEffect},
		{"shmdt", PointerEffect::NoEffect},
		{"shmget", PointerEffect::NoEffect},
		{"sigaction", PointerEffect::NoEffect},
		{"sigaddset", PointerEffect::NoEffect},
		{"sigaltstack", PointerEffect::NoEffect},
		{"sigdelset", PointerEffect::NoEffect},
		{"sigemptyset", PointerEffect::NoEffect},
		{"sigfillset", PointerEffect::NoEffect},
		{"sigisemptyset", PointerEffect::NoEffect},
		{"sigismember", PointerEffect::NoEffect},
		{"siglongjmp", PointerEffect::NoEffect},
		{"sigprocmask", PointerEffect::NoEffect},
		{"sigsuspend", PointerEffect::NoEffect},
		{"sleep", PointerEffect::NoEffect},
		{"snprintf", PointerEffect::NoEffect},
		{"socket", PointerEffect::NoEffect},
		{"socketpair", PointerEffect::NoEffect},
		{"sprintf", PointerEffect::NoEffect},
		{"srand", PointerEffect::NoEffect},
		{"srandom", PointerEffect::NoEffect},
		{"sscanf", PointerEffect::NoEffect},
		{"stat", PointerEffect::NoEffect},
		{"stat64", PointerEffect::NoEffect},
		{"statfs", PointerEffect::NoEffect},
		{"statvfs", PointerEffect::NoEffect},
		{"statvfs64", PointerEffect::NoEffect},
		{"strcasecmp", PointerEffect::NoEffect},
		{"strcmp", PointerEffect::NoEffect},
		{"strcoll", PointerEffect::NoEffect},
		{"strcspn", PointerEffect::NoEffect},
		{"strfmon", PointerEffect::NoEffect},
		{"strftime", PointerEffect::NoEffect},
		{"strlen", PointerEffect::NoEffect},
		{"strncasecmp", PointerEffect::NoEffect},
		{"strncmp", PointerEffect::NoEffect},
		{"strspn", PointerEffect::NoEffect},
		{"symlink", PointerEffect::NoEffect},
		{"sysconf", PointerEffect::NoEffect},
		{"sysinfo", PointerEffect::NoEffect},
		{"syslog", PointerEffect::NoEffect},
		{"system", PointerEffect::NoEffect},
		{"tcgetattr", PointerEffect::NoEffect},
		{"tcsetattr", PointerEffect::NoEffect},
		{"tgetent", PointerEffect::NoEffect},
		{"tgetflag", PointerEffect::NoEffect},
		{"tgetnum", PointerEffect::NoEffect},
		{"time", PointerEffect::NoEffect},
		{"timegm", PointerEffect::NoEffect},
		{"times", PointerEffect::NoEffect},
		{"tolower", PointerEffect::NoEffect},
		{"toupper", PointerEffect::NoEffect},
		{"towlower", PointerEffect::NoEffect},
		{"towupper", PointerEffect::NoEffect},
		{"tputs", PointerEffect::NoEffect},
		{"truncate", PointerEffect::NoEffect},
		{"tzset", PointerEffect::NoEffect},
		{"umask", PointerEffect::NoEffect},
		{"uname", PointerEffect::NoEffect},
		{"uncompress", PointerEffect::NoEffect},
		{"ungetc", PointerEffect::NoEffect},
		{"unlink", PointerEffect::NoEffect},
		{"unsetenv", PointerEffect::NoEffect},
		{"utime", PointerEffect::NoEffect},
		{"utimes", PointerEffect::NoEffect},
		{"vasprintf", PointerEffect::NoEffect},
		{"vfprintf", PointerEffect::NoEffect},
		{"vprintf", PointerEffect::NoEffect},
		{"vsnprintf", PointerEffect::NoEffect},
		{"vsprintf", PointerEffect::NoEffect},
		{"wait", PointerEffect::NoEffect},
		{"wait3", PointerEffect::NoEffect},
		{"wait4", PointerEffect::NoEffect},
		{"waitpid", PointerEffect::NoEffect},
		{"wcrtomb", PointerEffect::NoEffect},
		{"wctomb", PointerEffect::NoEffect},
		{"wctype", PointerEffect::NoEffect},
		{"werase", PointerEffect::NoEffect},
		{"wgetch", PointerEffect::NoEffect},
		{"write", PointerEffect::NoEffect},
		{"writev", PointerEffect::NoEffect},

		{"sin", PointerEffect::NoEffect},
		{"cos", PointerEffect::NoEffect},
		{"sinf", PointerEffect::NoEffect},
		{"cosf", PointerEffect::NoEffect},
		{"asin", PointerEffect::NoEffect},
		{"acos", PointerEffect::NoEffect},
		{"tan", PointerEffect::NoEffect},
		{"atan", PointerEffect::NoEffect},
		{"fabs", PointerEffect::NoEffect},
		{"pow", PointerEffect::NoEffect},
		{"floor", PointerEffect::NoEffect},
		{"ceil", PointerEffect::NoEffect},
		{"seed48", PointerEffect::NoEffect},
		{"lrand48", PointerEffect::NoEffect},
		{"abort", PointerEffect::NoEffect},
		{"exit", PointerEffect::NoEffect},
		{"sqrt", PointerEffect::NoEffect},
		{"sqrtf", PointerEffect::NoEffect},
		{"hypot", PointerEffect::NoEffect},
		{"rand", PointerEffect::NoEffect},
		{"random", PointerEffect::NoEffect},
		{"_ZdaPv", PointerEffect::NoEffect},
		{"fesetround", PointerEffect::NoEffect},
		{"putchar", PointerEffect::NoEffect},
		{"regcomp", PointerEffect::NoEffect},
		{"regexec", PointerEffect::NoEffect},
		{"regerror", PointerEffect::NoEffect},
		{"regfree", PointerEffect::NoEffect},

		{"malloc", PointerEffect::Malloc},
		{"calloc", PointerEffect::Malloc},
		{"valloc", PointerEffect::Malloc},
		{"shmat", PointerEffect::Malloc},
		{"strdup", PointerEffect::Malloc},
		{"strndup", PointerEffect::Malloc},
		{"memalign", PointerEffect::Malloc},
		// These functions will implicitly call malloc
		{"ctime", PointerEffect::Malloc},
		{"fopen", PointerEffect::Malloc},
		{"getlogin", PointerEffect::Malloc},
		{"opendir", PointerEffect::Malloc},
		{"popen", PointerEffect::Malloc},
		{"tempnam", PointerEffect::Malloc},
		{"textdomain", PointerEffect::Malloc},
		{"tgetstr", PointerEffect::Malloc},
		{"ttyname", PointerEffect::Malloc},
		{"tmpfile", PointerEffect::Malloc},
		{"strerror", PointerEffect::Malloc},
		// The mangled name of C++ new operators
		{"_Znwj", PointerEffect::Malloc},
		{"_ZnwjRKSt9nothrow_t", PointerEffect::Malloc},
		{"_Znwm", PointerEffect::Malloc},
		{"_ZnwmRKSt9nothrow_t", PointerEffect::Malloc},
		{"_Znaj", PointerEffect::Malloc},
		{"_ZnajRKSt9nothrow_t", PointerEffect::Malloc},
		{"_Znam", PointerEffect::Malloc},
		{"_ZnamRKSt9nothrow_t", PointerEffect::Malloc},

		{"getcwd", PointerEffect::Realloc},
		{"mmap", PointerEffect::Realloc},
		{"realloc", PointerEffect::Realloc},
		{"strtok", PointerEffect::Realloc},
		{"strtok_r", PointerEffect::Realloc},

		{"__ctype_b_loc", PointerEffect::ReturnStatic},
		{"__errno_location", PointerEffect::ReturnStatic},
		{"__h_errno_location", PointerEffect::ReturnStatic},
		{"__res_state", PointerEffect::ReturnStatic},
		{"bindtextdomain", PointerEffect::ReturnStatic},
		{"fdopen", PointerEffect::ReturnStatic},
		{"getenv", PointerEffect::ReturnStatic},
		{"getgrgid", PointerEffect::ReturnStatic},
		{"getgrnam", PointerEffect::ReturnStatic},
		{"gethostbyaddr", PointerEffect::ReturnStatic},
		{"gethostbyname", PointerEffect::ReturnStatic},
		{"getpwent", PointerEffect::ReturnStatic},
		{"getpwnam", PointerEffect::ReturnStatic},
		{"getpwuid", PointerEffect::ReturnStatic},
		{"getservbyname", PointerEffect::ReturnStatic},
		{"gettext", PointerEffect::ReturnStatic},
		{"gmtime", PointerEffect::ReturnStatic},
		{"localtime", PointerEffect::ReturnStatic},
		{"readdir", PointerEffect::ReturnStatic},
		{"setlocale", PointerEffect::ReturnStatic},
		{"tgoto", PointerEffect::ReturnStatic},
		{"tparm", PointerEffect::ReturnStatic},
		{"inet_ntoa", PointerEffect::ReturnStatic},

		{"fgets", PointerEffect::ReturnArg0},
		{"gets", PointerEffect::ReturnArg0},
		{"memchr", PointerEffect::ReturnArg0},
		{"stpcpy", PointerEffect::ReturnArg0},
		{"strcat", PointerEffect::ReturnArg0},
		{"strchr", PointerEffect::ReturnArg0},
		{"strcpy", PointerEffect::ReturnArg0},
		{"strerror_r", PointerEffect::ReturnArg0},
		{"strncat", PointerEffect::ReturnArg0},
		{"strncpy", PointerEffect::ReturnArg0},
		{"strpbrk", PointerEffect::ReturnArg0},
		{"strptime", PointerEffect::ReturnArg0},
		{"strrchr", PointerEffect::ReturnArg0},
		{"strstr", PointerEffect::ReturnArg0},
		// Actually the return value of signal() will NOT alias its second argument (first pointer-type argument), but if you call it twice the return values may alias. We're making conservative assumption here
		{"signal", PointerEffect::ReturnArg0},

		{"freopen", PointerEffect::ReturnArg2},

		{"strtod", PointerEffect::StoreArg0ToArg1},
		{"strtof", PointerEffect::StoreArg0ToArg1},
		{"strtol", PointerEffect::StoreArg0ToArg1},
		{"strtold", PointerEffect::StoreArg0ToArg1},
		{"strtoll", PointerEffect::StoreArg0ToArg1},
		{"strtoul", PointerEffect::StoreArg0ToArg1},

		{"bcopy", PointerEffect::MemcpyArg0ToArg1},
		{"llvm.memcpy.i32", PointerEffect::MemcpyArg0ToArg1},
		{"llvm.memcpy.p0i8.p0i8.i32", PointerEffect::MemcpyArg0ToArg1},
		{"llvm.memcpy.i64", PointerEffect::MemcpyArg0ToArg1},
		{"llvm.memcpy.p0i8.p0i8.i64", PointerEffect::MemcpyArg0ToArg1},
		{"llvm.memmove.i32", PointerEffect::MemcpyArg0ToArg1},
		{"llvm.memmove.p0i8.p0i8.i32", PointerEffect::MemcpyArg0ToArg1},
		{"llvm.memmove.i64", PointerEffect::MemcpyArg0ToArg1},
		{"llvm.memmove.p0i8.p0i8.i64", PointerEffect::MemcpyArg0ToArg1},
		{"memccpy", PointerEffect::MemcpyArg0ToArg1},
		{"memcpy", PointerEffect::MemcpyArg0ToArg1},
		{"memmove", PointerEffect::MemcpyArg0ToArg1},
		{"wmemcpy", PointerEffect::MemcpyArg0ToArg1},

		{"memset", PointerEffect::Memset},
		{"llvm.memset.p0i8.i64", PointerEffect::Memset},
		{"llvm.memset.p0i8.i32", PointerEffect::Memset},
	};

	std::sort(table.begin(), table.end());
	assert(std::unique(table.begin(), table.end()) == table.end());
}

PointerEffect ExternalPointerEffectTable::lookup(StringRef name) const
{
	// Find the corresponding entry using binary search
	auto itr = std::lower_bound(table.begin(), table.end(), name,
		[] (const MappingType& entry, const StringRef& name)
		{
			return entry.first < name;
		});

	if (itr == table.end() || itr->first != name)
		return PointerEffect::UnknownEffect;
	else
		return itr->second;
}

}
