int login_akun(const char *username, const char *password)
{
    for (int i = 0; i <= usermaks; i++)
    {
        printf("%s", data[i]);
        if (strcmp(data[i].username, username) == 0 && strcmp(data[i].password, password) == 0)
        {
            return 1;
        }
    }
    return 0;
}