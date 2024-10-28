#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_DESCRIPTION("linear");
MODULE_LICENSE("GPL");

// consturction function
int linear_init(void)
{
    struct task_struct* current_task;  // construct task structure
    
    for_each_process(current_task)  // for every process
    {
        // print out the id, name, and state
        printk("pid: %d |pname: %s |state: %ld", current_task->pid,
                current_task->comm, current_task->state);
    }

    return 0;
}

// destruction function
void linear_exit(void)
{
    // do nothing
}

// call functions
module_init(linear_init);
module_exit(linear_exit);