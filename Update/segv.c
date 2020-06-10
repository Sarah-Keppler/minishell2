int main(void)
{
    char *mem = "Je suis une mémoire qui va segv, yes !";

    for (int i = 0; mem[0] != 'S'; ++i)
        mem[i] = 'S';
}
