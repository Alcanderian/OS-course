/* Verifies that lowering a thread's priority so that it is no
   longer the highest-priority thread in the system causes it to
   yield immediately. */

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/thread.h"

static thread_func changing_thread;

void
test_priority_change (void)
{
  /* This test does not work with the MLFQS. */
  ASSERT (!thread_mlfqs);

  /* About `putchar('%d')`:
   *   Comment all `msg` and uncomment `putchar`, then we can see the actual
   *   result of the test. Because msg runs too slow that will impact the
   *   result. For example, in ubuntu-14.04 and ubuntu-16.04, we will see
   *   different result if we only change `threads_ser_priority`.
   */
  msg ("Creating a high-priority thread 2.");
  /* putchar ('1'); */
  thread_create ("thread 2", PRI_DEFAULT + 1, changing_thread, NULL);
  msg ("Thread 2 should have just lowered its priority.");
  /* putchar ('3'); */
  thread_set_priority (PRI_DEFAULT - 2);
  msg ("Thread 2 should have just exited.");
  /* putchar ('5'); */
}

static void
changing_thread (void *aux UNUSED)
{
  msg ("Thread 2 now lowering priority.");
  /* putchar ('2'); */
  thread_set_priority (PRI_DEFAULT - 1);
  msg ("Thread 2 exiting.");
  /* putchar ('4'); */
}
