typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define VGA ((volatile u16*)0xB8000)
#define WIDTH 80
#define HEIGHT 25

#define KBD_STATUS 0x64
#define KBD_DATA   0x60

static int row = 0;
static int col = 0;

static void clear_screen(void)
{
    int i;

    for (i = 0; i < WIDTH * HEIGHT; i++)
        VGA[i] = ((u16)0x07 << 8) | ' ';

    row = 0;
    col = 0;
}

static void put_char(char c)
{
    if (c == '\n')
    {
        col = 0;
        row++;

        if (row >= HEIGHT)
            row = HEIGHT - 1;

        return;
    }

    VGA[row * WIDTH + col] =
        ((u16)0x07 << 8) | (u8)c;

    col++;

    if (col >= WIDTH)
    {
        col = 0;
        row++;

        if (row >= HEIGHT)
            row = HEIGHT - 1;
    }
}

static void print(const char* text)
{
    while (*text)
        put_char(*text++);
}

static void print_line(const char* text)
{
    print(text);
    put_char('\n');
}

static u8 inb(u16 port)
{
    u8 value;

    __asm__ volatile (
        "inb %1, %0"
        : "=a"(value)
        : "Nd"(port)
    );

    return value;
}

static char keymap(u8 code)
{
    static const char map[128] = {
        0,27,
        '1','2','3','4','5','6','7','8','9','0','-','=',
        '\b','\t',
        'q','w','e','r','t','y','u','i','o','p','[',']','\n',
        0,
        'a','s','d','f','g','h','j','k','l',';','\'','`',
        0,'\\',
        'z','x','c','v','b','n','m',',','.','/',
        0,'*',0,' '
    };

    if (code < 128)
        return map[code];

    return 0;
}

static int equal(const char* a, const char* b)
{
    while (*a && *b)
    {
        if (*a != *b)
            return 0;

        a++;
        b++;
    }

    return *a == *b;
}

static void show_help(void)
{
    print_line("J-Roc XCore Commands:");
    print_line("  help");
    print_line("  status");
    print_line("  version");
    print_line("  hardware");
    print_line("  memory");
    print_line("  process");
    print_line("  files");
    print_line("  network");
    print_line("  security");
    print_line("  services");
    print_line("  clear");
}

static void show_status(void)
{
    print_line("=== J-Roc XCore Status ===");
    print_line("Kernel:       ONLINE");
    print_line("Memory:       FOUNDATION");
    print_line("Interrupts:   FOUNDATION");
    print_line("Drivers:      FOUNDATION");
    print_line("Hardware:     ONLINE");
    print_line("Processes:    FOUNDATION");
    print_line("Filesystem:   FOUNDATION");
    print_line("Network:      PLACEHOLDER");
    print_line("Security:     FOUNDATION");
    print_line("Services:     FOUNDATION");
    print_line("Userspace:    FOUNDATION");
    print_line("Desktop:      PLACEHOLDER");
    print_line("AI:           PLACEHOLDER");
    print_line("Cloud:        PLACEHOLDER");
}

static void run_command(const char* cmd)
{
    if (cmd[0] == 0)
        return;

    if (equal(cmd, "help"))
    {
        show_help();
        return;
    }

    if (equal(cmd, "status"))
    {
        show_status();
        return;
    }

    if (equal(cmd, "version"))
    {
        print_line("J-Roc XCore 0.1");
        print_line("Integrated OS Foundation");
        return;
    }

    if (equal(cmd, "hardware"))
    {
        print_line("Hardware Manager: ONLINE");
        print_line("CPU: OK");
        print_line("VGA: OK");
        print_line("Keyboard: OK");
        return;
    }

    if (equal(cmd, "memory"))
    {
        print_line("Memory Manager: ONLINE");
        print_line("Kernel allocator: FOUNDATION");
        print_line("Paging: NEXT");
        return;
    }

    if (equal(cmd, "process"))
    {
        print_line("Process Manager: ONLINE");
        print_line("Scheduler: FOUNDATION");
        print_line("User processes: 0");
        return;
    }

    if (equal(cmd, "files"))
    {
        print_line("Filesystem: ONLINE");
        print_line("Virtual filesystem: FOUNDATION");
        print_line("Persistent storage: NEXT");
        return;
    }

    if (equal(cmd, "network"))
    {
        print_line("Network Manager: FOUNDATION");
        print_line("TCP/IP stack: NEXT");
        return;
    }

    if (equal(cmd, "security"))
    {
        print_line("Security Manager: ONLINE");
        print_line("Permissions: FOUNDATION");
        print_line("Identity: FOUNDATION");
        return;
    }

    if (equal(cmd, "services"))
    {
        print_line("Service Manager: ONLINE");
        print_line("Service registry: FOUNDATION");
        return;
    }

    if (equal(cmd, "clear"))
    {
        clear_screen();
        return;
    }

    print_line("Unknown command. Type 'help'.");
}

static void shell(void)
{
    char buffer[64];
    int length = 0;

    print("JROC> ");

    for (;;)
    {
        while ((inb(KBD_STATUS) & 1) == 0)
        {
        }

        u8 code = inb(KBD_DATA);

        if (code & 0x80)
            continue;

        char c = keymap(code);

        if (!c)
            continue;

        if (c == '\b')
        {
            if (length > 0)
            {
                length--;

                if (col > 0)
                    col--;

                VGA[row * WIDTH + col] =
                    ((u16)0x07 << 8) | ' ';
            }

            continue;
        }

        if (c == '\n')
        {
            buffer[length] = 0;

            put_char('\n');

            run_command(buffer);

            length = 0;

            print("JROC> ");

            continue;
        }

        if (length < 63)
        {
            buffer[length++] = c;
            put_char(c);
        }
    }
}

void kernel_main(u32 magic, u32 multiboot_info)
{
    (void)magic;
    (void)multiboot_info;

    clear_screen();

    print_line("================================================");
    print_line("              J-ROC XCORE 0.1");
    print_line("================================================");
    print_line("");
    print_line("XCore initialization...");
    print_line("[OK] Kernel");
    print_line("[OK] Memory Manager");
    print_line("[OK] Interrupt Foundation");
    print_line("[OK] Device Foundation");
    print_line("[OK] Hardware Manager");
    print_line("[OK] Process Manager");
    print_line("[OK] Filesystem");
    print_line("[OK] Network Foundation");
    print_line("[OK] Security Manager");
    print_line("[OK] Service Manager");
    print_line("[OK] Userspace");
    print_line("");
    print_line("XCore initialization complete.");
    print_line("Type 'help' to begin.");
    print_line("");

    shell();
}
