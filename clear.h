void clear_screen() {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}