#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char readInput(int *num);

int main()
{
    int total_count;
    int ranges[101];
    int start, end, i, j, query, total_in_range;

    while (readInput(&query) != EOF)
    {
        memset(ranges, 0, sizeof(ranges));

        for (j = 0; j < query; j++)
        {
            scanf("%d %d", &start, &end);

            for (i = start; i <= end; i++)
                ++ranges[i];
        }

        total_count = 0;
        scanf("%d", &j);

        if (ranges[j])
        {
            for (i = 1; i < j; i++)
                total_count += ranges[i];

            printf("%d found from %d to %d\n", j, total_count, (total_count + ranges[j] - 1));
        }
        else
            printf("%d not found\n", j);
    }

    return 0;
}

char readInput(int *num)
{
    return scanf("%d", num) == 1 ? TRUE : EOF;
}
