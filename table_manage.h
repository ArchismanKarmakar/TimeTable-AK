#define pause()                               \
    do                                        \
    {                                         \
        cout << "\n";                          \
    } while (cin.get() != '\n');              \
    do                                        \
    {                                         \
        cout << "Press a key to continue..."; \
    } while (cin.get() != '\n')