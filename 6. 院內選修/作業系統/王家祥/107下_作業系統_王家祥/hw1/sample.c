#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>

MODULE_DESCRIPTION("Sample_module");
MODULE_LICENSE("GPL");

// declare the list structure with four integers and one pointer
struct numlist{
    int id;
    int yy;
    int mm;
    int dd;
    struct list_head list;
};

struct numlist numhead;  // create new list numhead

//consturction function
static int __init sample_init(void)
{
    struct numlist *listnode;  // temporary node for appending behind
    struct list_head *itr;  // iteration pointer
    struct numlist *p;  // temporary node for printing results
    int i;  // loop index
    int stid = 105061212;  // initial value of student ID
    int yr = 1998;  // initial value of year
    int mn = 5;  // initial value of month
    int dy = 20;  // initial value of day
    
    INIT_LIST_HEAD(&numhead.list);  // initializing the list

    for(i=0; i<5; i++)  // repeat five times
    {
        listnode = (struct numlist *)vmalloc(sizeof(struct numlist));  // allocate dynamic memories
        listnode->id = stid;  // write values
        listnode->yy = yr;
        listnode->mm = mn;
        listnode->dd = dy;
        
        list_add_tail(&listnode->list,&numhead.list);  // append the node at the end of the list

        stid+=2; yr+=1; mn-=1; dy+=2;  // data increment
    }

    list_for_each(itr,&numhead.list){  // for each list node
        p = list_entry(itr,struct numlist,list);  // point to each node
        printk("%d, %d-%d-%d.\n", p->id, p->dd, p->mm, p->yy);  // print the data
    }

    return 0;
}

// destruction function
static void __exit sample_exit(void)
{
    struct list_head *itr,*n;  // iteration pointers
    struct numlist *p;  // temporary node for deleting

    list_for_each_safe(itr, n, &numhead.list)  // for each list node
    {
        list_del(itr);  // delete the node
        p = list_entry(itr, struct numlist, list);  // point to each node
        vfree(p);  // release memories
    }
}

// call functions
module_init(sample_init);
module_exit(sample_exit);
