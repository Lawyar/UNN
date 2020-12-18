#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct filezzz{
    size_t size;
    char name[256];
};

struct filezzz help;

void bubble_sort(struct filezzz member[], int len, struct filezzz help)
{
    for (int i = 0; i <= len; i++)
    {
        for (int j = len - 1; j > i; j--)
        {
            if (strcmp(member[j].name, member[j - 1].name) < 0 && member[j].name[0] != '\0')
            {
                help = member[j - 1];
                member[j - 1] = member[j];
                member[j] = help;
            }
        }
    }

}

void quick_sort(struct filezzz smth[], int left, int right)
{
    char pivot[256];
    int pivot_1;
    int l_hold = left;
    int r_hold = right;
    strcpy(pivot, smth[left].name);
    while (left < right)
    {
        while ((strcmp(smth[right].name, pivot) >= 0) && (left < right))
            right--;
        if (left != right)
        {
            strcpy(smth[left].name, smth[right].name);
            smth[left].size = smth[right].size;
            left++;
        }
        while ((strcmp(smth[left].name, pivot) <= 0) && (left < right))
            left++;
        if (left != right)
        {
            strcpy(smth[right].name, smth[left].name);
            smth[right].size = smth[left].size;
            right--;
        }
    }
    strcpy(smth[left].name, pivot);
    pivot_1 = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot_1)
        quick_sort(smth, left, pivot_1 - 1);
    if (right > pivot_1)
        quick_sort(smth, pivot_1 + 1, right);
}

int main()
{
    DIR *mydir;

    struct dirent *myfile;
    struct stat mystat;
    struct filezzz first[512];

    char arrname[256][256];
    char buf[512];
    char dir[256];
    int counter = 0;
    printf("Enter directory: ");
    scanf("%s", dir);

    mydir = opendir(dir);
    while((myfile = readdir(mydir)) != NULL)
    {
        strcpy(buf, dir);
        strcat(buf, "/");
        strcat(buf, myfile->d_name);
        stat(buf, &mystat);
        first[counter].size = mystat.st_size;
        strcpy(first[counter].name, myfile->d_name);
        counter++;
    }


    printf("Choose sorting method:\n'1':bubble sort\n'2':shaker sort\n");
    int sortmeth;
    scanf("%d", &sortmeth);
    mydir = opendir(dir);
    if(sortmeth == 1)
    {
        clock_t quick = clock();
        bubble_sort(first, sizeof(first) / sizeof(first[0]), help);
        clock_t quicky = clock();
        printf("Sort time: %f\n", (double)(quicky - quick) / CLOCKS_PER_SEC);
        for(int i = 0; i < sizeof(first) / sizeof(first[0]); i++)
        {
            if (isalnum(first[i].name[0])){
                printf("%zu\t", first[i].size);
                printf("%s\n", first[i].name);
            }
        }
        printf("Sort time: ");
    }
    if(sortmeth == 2)
    {
        clock_t quick = clock();
        quick_sort(first, 0, sizeof(first) / sizeof(first[0]));
        clock_t quicky = clock();
        printf("Sort time: %f\n", (double)(quicky - quick) / CLOCKS_PER_SEC);
        for(int i = 0; i < sizeof(first) / sizeof(first[0]); i++)
        {
            if (isalnum(first[i].name[0]))
            {
                printf("%zu\t", first[i].size);
                printf("%s\n", first[i].name);
            }
        }
    }
    closedir(mydir);
}
