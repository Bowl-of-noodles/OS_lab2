#define RD_MY_FPU _IOWR('a','a', struct fpu_request*)
#define RD_MY_INODE _IOWR('a','b', struct inode_request*)

struct my_fpu {
    unsigned int last_cpu; /* Last cpu in which regs this context load. -1 is mean what context in this struct more new than regs */
    unsigned long avx512_timestamp; /* timestamp then AVX512 used to switch context*/

    unsigned int cwd; /* Control word - ���������� �������� ������ ������������ - ���������� ���������, �����������, ����� ������������, ��������������� �������� � ����*/
    unsigned int swd; /* Status word - ������� ��������� ������������ - ����� ������� �� 0, ��������� ����������, �������, ������������, ��������� � �.�.*/
    unsigned int twd; /* Tag word - �������� ����������� ����� (16/32 ��� - �� 2/4 �� ������ �������) 00- ������. �� ����, 01 - �������� ����, 10 - ����.�����, 11 - �����. ������*/
    unsigned int fip; /* IP Offset */
    unsigned int fcs; /* IP selector */
    unsigned int foo; /* Operand Pointer offset */
    unsigned int fos; /* Operand Pointer selector */

    unsigned int stack[20]; /* r0..r7 - ���� ������������ - 8 ��������� �� 80 ��� (8 * 4 * 20)*/
};


struct my_inode {
	unsigned long	i_mode;
	unsigned short	i_opflags;
	unsigned int	i_uid;
	unsigned int	i_gid;
	unsigned int	i_flags;

    unsigned long	i_ino;

    unsigned long	i_rdev;
	unsigned long	i_size;
	long	i_atime_sec;
	long	i_atime_nsec;
	long	i_mtime_sec;
	long	i_mtime_nsec;
	long	i_ctime_sec;
	long	i_ctime_nsec;
	unsigned short      i_bytes;
	unsigned short	    i_blkbits;
	unsigned short		i_write_hint;
	uint64_t		i_blocks;
    unsigned long		dirtied_when;	/* jiffies of first dirtying */
	unsigned long		dirtied_time_when;
};

struct fpu_request {
	int32_t pid;
	struct my_fpu fpu;
};

struct inode_request {
    char* path;
    struct my_inode inode;
};
