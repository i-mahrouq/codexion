
#include "codexion.h"

static int has_priority(t_dongle *d, t_coder *a, t_coder *b)
{
    long long da;
    long long db;

    if (d->sim->config->scheduler == FIFO)
        return (a->request_time < b->request_time);

    /* EDF: deadline = last_compile_start + time_to_burnout */
    da = a->last_compile_start
       + d->sim->config->time_to_burnout;

    db = b->last_compile_start
       + d->sim->config->time_to_burnout;

    if (da == db)
        return (a->id < b->id);

    return (da < db);
}

static void swap(t_dongle *d, int i, int j)
{
    t_coder *tmp;

    tmp = d->heap[i];
    d->heap[i] = d->heap[j];
    d->heap[j] = tmp;
}


static void bubble_up(t_dongle *d, int i)
{
    int parent;

    while (i > 0)
    {
        parent = (i - 1) / 2;
        if (has_priority(d, d->heap[i], d->heap[parent]))
        {
            swap(d, i, parent);
            i = parent;
        }
        else
            break ;
    }
}


static void sink_down(t_dongle *d, int i)
{
    int left;
    int right;
    int best;

    while (1)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        best = i;
        if (left < d->heap_size && has_priority(d, d->heap[left], d->heap[best]))
            best = left;
        if (right < d->heap_size && has_priority(d, d->heap[right], d->heap[best]))
            best = right;
        if (best == i)
            break ;
        swap(d, i, best);
        i = best;
    }
}

void heap_push(t_dongle *d, t_coder *c)
{
    if (d->heap_size >= 2)
        return ;

    d->heap[d->heap_size] = c;
    d->heap_size++;

    bubble_up(d, d->heap_size - 1);
}

t_coder *heap_pop(t_dongle *d)
{
    t_coder *top;

    if (d->heap_size == 0)
        return NULL;
    top = d->heap[0];
    d->heap[0] = d->heap[--d->heap_size];
    sink_down(d, 0);
    return top;
}

t_coder *heap_peek(t_dongle *d)
{
    if (d->heap_size == 0)
        return NULL;
    return d->heap[0];
}