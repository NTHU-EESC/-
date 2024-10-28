#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_DESCRIPTION("dfs");
MODULE_LICENSE("GPL");

// DFS algorithm
void DFS(struct task_struct* curr)
{
    struct task_struct* p;  // children node
    struct list_head* itr;  // iteration pointer

    // print out the id, name, and state
    printk("pid: %d |pname: %s |state: %ld", curr->pid, curr->comm, curr->state);

    list_for_each(itr, &curr->children){  // for all children
        p = list_entry(itr, struct task_struct, sibling);  // search all siblings
        DFS(p);  // keep finding
    }

}

// consturction function
int dfs_init(void)
{
    struct task_struct* current_task = &init_task;  // construct task structure and initialize

    DFS(current_task);  // list all tasks by DFS

    return 0;
}

// destruction function
void dfs_exit(void)
{
    // do nothing
}

// call functions
module_init(dfs_init);
module_exit(dfs_exit);