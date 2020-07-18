# The Eudyptula Challenge
#Instructions
Welcome to the Eudyptula Challenge!

This "challenge" is a series of Linux kernel programming exercises
starting out small, and in the end, if all goes well, you'll be the
maintainer of a subsystem, if you so desire.  Well, maybe not a
maintainer, but you will be qualified enough to point out any problems
that your favorite maintainer is causing, and that's actually way more
fun than being in charge.

All of these tasks will be done through email, and will require you to
write, modify, and submit Linux kernel patches and code of all different
types.

First off, some housekeeping rules.

You have been assigned a "unique" id.  This id is required when
submitting your results, as I (a dumb script) need some way to determine
what is going on.  So, please, for every email you write to me from now
on, use your id in the Subject: line like this:

    [YOUR_ID] Task 02 results

And yes, if you haven't guessed it already, "YOUR_ID" is your
unique id.  Please don't lose it.  I can, through some difficulty,
figure it out again, but we really don't want to have to get my human
involved in this process, that only slows things down.

You should be able to just hit "reply" on the task email and all should
be fine, if not, the scripts will notify you.

Always send submissions in from this email address, the one that you
signed up with, emails from any other address will be silently
discarded.  If you need to change email addresses in the future, just
email me and tell me your existing id (YOUR_ID), your original
email address, and your new email address, and it will be changed.

When you submit a task, you will receive an autoresponse saying where
you are in the queue.  If you do not receive this autoresponse, I have
not received your task, something went wrong, and it needs to be resent.

Secondly, no HTML email, or base64-mime attachments.  If you have made
it this far, you have successfully sent a non-HTML email, which is
wonderful (kids these days...), but for all tasks you can't send base64
attachments, as I don't know what to do with them.  Just a "normal"
attachment, in text form, is fine, and preferred.  If you have problems
with this, please consult your email client's documentation on how to do
this.

Thirdly, don't use Gmail or Microsoft Exchange for this set of tasks.
Yes, it can be done, but it's really hard, and you really have to know
what you are doing.  If you get back "I can't understand this response,
please try again" message, you might want to switch to a different email
client / server and try it again, and notify me of your email address
change.  Ah, now you see why you use an id and not an email address, we
didn't just fall off of the turnip truck yesterday.

Fourthly, this challenge is meant to be done over a period of time.
Don't rush things, there's no hurry, I'm not going anywhere, and neither
are you.  So sit back, take your time, and enjoy the process.  Life is
about the journey, not the end result, as that's the same for everyone.

Responses to submissions can sometimes take a few days, or weeks, or
they can be a few minutes, depending on the load of the system.  There
are many thousands of people currently taking this challenge and the
scripts get easily backlogged at times.  If you ever feel that you
missed an email, just ask, and research will be done to see what
happened.  Sometimes new task emails do get delayed, but it should only
be an hour or so, never more than a day to get a new task once you have
completed one.  If you have not received a new task within a day of a
task being marked as completed, please send a reminder email to find out
what went wrong.

Fifth, as stated on the challenge's home page, please do your work on
your own.  A number of participants have, in the past, posted the
answers to the tasks on github and other public code sites.  This
instantly caused their solutions to be copied and submitted as answers
from other people.  I'm sure you don't want to have others copy your
hard work.  Doing these challenges does not mean you cannot research and
try to find out how to do the tasks from existing kernel code and
documentation.  You are expected to do that.  When you do copy code or
scripts, please be sure to properly attribute where you copied it from,
otherwise I am going to just assume you are trying to pass it off as
your own work, which is not a good thing at all.

If you are found to have posted your code publicly, or asked for help in
public locations, or copied code from public locations without properly
attributing it, or tried to cheat or fake challenge results in any way,
you will be removed from the challenge instantly.  In short, do your own
work, and keep it to yourself.

Finally, if you have any questions about a task, or need help with
something, feel free to ask.  I'll alert my human that something is
going on, and they will get back to you in a few days with answers.

Expect a follow-on email from this with your first task.  Responses to
tasks might take a few days, depending on the load on my system, and any
nasty bugs that show up.  Remember the fourth point again, you'll need
to keep that in mind during this.

As the Big Penguin says, "Have fun!"

This is Task 01 of the Eudyptula Challenge
------------------------------------------

Write a Linux kernel module, and stand-alone Makefile, that when loaded
prints to the kernel debug log level, "Hello World!"  Be sure to make
the module able to be unloaded as well.

The Makefile should be able to build the kernel module against the
source of the currently-running kernel as well as being able to accept
an arbitrary kernel sources directory from an environment variable.

Please show proof of this module being built, and running, in your
kernel.  What this proof is is up to you.  I'm sure you can come up with
something.  Also be sure to send the kernel module you wrote, along with
the Makefile you created to build the module.

Remember to use your ID assigned in the Subject: line when responding to
this task, so that I can figure out who to attribute it to.  You can
just respond to the task with the answers and all should be fine.

If you forgot, your id is "YOUR_ID".  But of course you have not
forgotten that yet, you are better than that.

This is Task 02 of the Eudyptula Challenge
------------------------------------------

Now that you have written your first kernel module, it's time to take
off the training wheels and move on to building a custom kernel.  No
more distro kernels for you.  For this task you must run your own
kernel.  And use git!  Exciting, isn't it?  No?  Oh, ok...

The tasks for this round are:
  - Download Linus's latest git tree from git.kernel.org (you have to
    figure out which one is his.  It's not that hard, just remember what
    his last name is and you should be fine.)
  - Build it, install it, and boot it.  You can use whatever kernel
    configuration options you wish to use, but you must enable
    CONFIG_LOCALVERSION_AUTO=y.
  - Show proof of booting this kernel.  Bonus points if you do it on a
    "real" machine, and not a virtual machine (virtual machines are
    acceptable, but come on, real kernel developers don't mess around
    with virtual machines, they are too slow.  Oh yeah, we aren't real
    kernel developers just yet.  Well, I'm not anyway, I'm just a
    script...)  Again, proof of running this kernel is up to you, I'm
    sure you can do well.

Hint, you should look into the 'make localmodconfig' option, and base
your kernel configuration on a working distro kernel configuration.
Don't sit there and answer all 1625 different kernel configuration
options by hand, even I, a foolish script, know better than to do that!

After doing this, don't throw away that kernel, git tree, and
configuration file.  You'll be using it for later tasks.  A working
kernel configuration file is a precious thing, all kernel developers
have one they have grown and tended to over the years.  This is the
start of a long journey with yours.  Don't discard it like was a broken
umbrella, it deserves better than that.

Remember to use your ID assigned in the subject line when responding to
this task, so that I can figure out who to attribute it to.

If you forgot, your id is "YOUR_ID".  But why do I repeat myself?
Of course you know your id, you made it through the first task just fine
with it.

This is Task 03 of the Eudyptula Challenge
------------------------------------------

Now that you have your custom kernel up and running, it's time to modify
it!

The tasks for this round are:
  - Take the kernel git tree from Task 02 and change the Makefile to
    modify the EXTRAVERSION field.  Do this in a way that the
    running kernel (after modifying the Makefile, rebuilding, and
    rebooting) has the characters "-eudyptula" in the version string.
  - Show proof of booting this kernel.  Extra cookies when you provide
    creative examples, especially if done in interpretive dance at your
    local pub.
  - Send a patch that shows the Makefile modified.  Do this in a manner
    that would be acceptable for merging in the kernel source tree.
    (Hint, read the file Documentation/SubmittingPatches and follow the
    steps there.)

Remember to use your ID assigned in the subject line when responding to
this task, so that I can figure out who to attribute it to.

If you forgot, your id is "YOUR_ID".  Surely I don't need to keep
saying this right?  I know, _you_ wouldn't forget, but someone else, of
course they would, so I'll just leave it here for those "others."

This is Task 04 of the Eudyptula Challenge
------------------------------------------

Wonderful job in making it this far.  I hope you have been having fun.
Oh, you're getting bored, just booting and installing kernels?  Well,
time for some pedantic things to make you feel that those kernel builds
are actually fun!

Part of the job of being a kernel developer is recognizing the proper
Linux kernel coding style.  The full description of this coding style
can be found in the kernel itself, in the Documentation/CodingStyle
file.  I'd recommend going and reading that right now.  It's pretty
simple stuff, and something that you are going to need to know and
understand.  There is also a tool in the kernel source tree in the
scripts/ directory called checkpatch.pl that can be used to test for
adhering to the coding style rules, as kernel programmers are lazy and
prefer to let scripts do their work for them...

Why a coding standard at all?  Because of your brain (yes, yours, not
mine, remember, I'm just some dumb shell scripts).  Once your brain
learns the patterns, the information contained really starts to sink in
better.  So it's important that everyone follow the same standard so
that the patterns become consistent.  In other words, you want to make
it really easy for other people to find the bugs in your code, and not
be confused and distracted by the fact that you happen to prefer 5
spaces instead of tabs for indentation.  Of course you would never
prefer such a thing, I'd never accuse you of that, it was just an
example, please forgive my impertinence!

Anyway, the tasks for this round all deal with the Linux kernel coding
style.  Attached to this message are is one kernel module that does not
follow the proper Linux kernel coding style rules.  Fix this file up,
AND fix up the final submission you did for Task 01, and send them back
to me as attachments in your response email.

Yes, the logic in attached second module is crazy, and probably wrong,
but don't focus on that, just look at the patterns here, and fix up the
coding style, do not remove lines of code.

Oh, and before you think "Ah, but I got the coding style right for Task
01, I already know this stuff!", remember that so far only 10 people,
out of over 4000, have gotten the coding style exactly right for their
Task 01 module.  Yes, you could be one of those people, but the odds are
not in your favor.  You should look at it again just to be sure.

So again, attach 2 files, this one fixed up, and your Task 01
submission.  Don't use base64 either, the scripts will instantly reject
it, you don't want to get on their bad side.

As always, please remember to use your ID in the subject line when
responding to this task, so that I can figure out who to attribute it
to.  And if you forgot (which of course you have not, we've been through
all of this before), your id is "YOUR_ID".

This is Task 05 of the Eudyptula Challenge
------------------------------------------

Yeah, you survived the coding style mess!  Now, on to some "real"
things, as I know you are getting bored by these so far.

So, two simple tasks this time around:
  - Take the kernel module you wrote for task 01, and modify it so that
    when any USB keyboard is plugged in, the module will be
    automatically loaded by the correct userspace hotplug tools (which
    are implemented by depmod / kmod / udev / mdev / systemd, depending
    on what distro you are using.)
  - Again, provide "proof" this all works.

Yes, so simple, and yet, it's a bit tricky.  As a hint, go read chapter
14 of the book, "Linux Device Drivers, 3rd edition."  Don't worry, it's
free, and online, no need to go buy anything.

As always, please remember to use your ID, yadda yadda yadda...
It's "YOUR_ID" of course.

This is Task 06 of the Eudyptula Challenge
------------------------------------------

Nice job with the module loading macros.  Those are tricky, but a very
valuable skill to know about, especially when running across them in
real kernel code.

Speaking of real kernel code, let's write some!

The tasks this time are:
  - Take the kernel module you wrote for task 01, and modify it to be a
    misc char device driver.  The misc interface is a very simple way to
    be able to create a character device, without having to worry about
    all of the sysfs and character device registration mess.  And what a
    mess it is, so stick to the simple interfaces wherever possible.
  - The misc device should be created with a dynamic minor number, no
    need running off and trying to reserve a real minor number for your
    test module, that would be crazy.
  - The misc device should implement the read and write functions.
  - The misc device node should show up in /dev/eudyptula.
  - When the character device node is read from, your assigned id is
    returned to the caller.
  - When the character device node is written to, the data sent to the
    kernel needs to be checked.  If it matches your assigned id, then
    return a correct write return value.  If the value does not match
    your assigned id, return the "invalid value" error value.
  - The misc device should be registered when your module is loaded, and
    unregistered when it is unloaded.
  - Provide some "proof" this all works properly.

As you will be putting your id into the kernel module, of course you
haven't forgotten it, but just to be safe, it's "YOUR_ID".

This is Task 07 of the Eudyptula Challenge
------------------------------------------

Great work with that misc device driver.  Isn't that a nice and simple
way to write a character driver?

Just when you think this challenge is all about writing kernel code,
this task is a throwback to your second one.  Yes, that's right,
building kernels.  Turns out that's what most developers end up doing:
tons and tons of rebuilds, not writing new code.  Sad, but it is a good
skill to know.

The task this round is:
  - Download the linux-next kernel for today.  Or tomorrow, just use
    the latest one.  It changes every day so there is no specific one
    you need to pick.  Build it.  Boot it.  Provide proof that you built
    and booted it.

What is the linux-next kernel?  Ah, that's part of the challenge.

For a hint, you should read the excellent documentation about how the
Linux kernel is developed in Documentation/development-process/ in the
kernel source itself.  It's a great read, and should tell you all you
never wanted to know about what Linux kernel developers do and how they
do it.

As always, please respond to this challenge with your id.  I know you
know what it is.  I'll not even include it this time, I trust you.
Don't make me feel that is a mistake.

This is Task 08 of the Eudyptula Challenge
------------------------------------------

We will come back to the linux-next kernel in a later exercise, so don't
go and delete that directory, you'll want it around.  But enough of
building kernels, let's write more code!

This task is much like the 06 task with the misc device, but this time
we are going to focus on another user/kernel interface, debugfs.  It is
rumored that the creator of debugfs said that there is only one rule for
debugfs use": "There are no rules when using debugfs."  So let's take
them up on that offer and see how to use it.

debugfs should be mounted by your distro in /sys/kernel/debug/.  If it
isn't, then you can mount it with the line:
        mount -t debugfs none /sys/kernel/debug/

Make sure it is enabled in your kernel, with the CONFIG_DEBUG_FS option,
you will need it for this task.

The tasks, in specifics are:

  - Take the kernel module you wrote for task 01, and modify it to
    create a debugfs subdirectory called "eudyptula".  In that
    directory, create the virtual file called "id".
  - This "id" file, operates just like it did for example 06, and uses
    the same logic there, the file is to be readable and writable by any
    user.
  - Submit this task as the first email.
  - Base your work on this submission, and create a new debugfs file
    called "jiffies".
  - This "jiffies" file is to be read-only by any user, and when read,
    should return the current value of the jiffies kernel timer.
  - Submit this result as a patch against the first email.
  - Base your work again on that submission, and create a final debugfs
    file called "foo".
  - The file "foo" needs to be writable only by root, but readable by
    anyone.  When writing to it, the value must be stored, up to one
    page of data.  When read, which can be done by any user, the value
    that is stored in it must be returned.  Properly handle the fact
    that someone could be reading from the file while someone else is
    writing to it (oh, a locking hint!)
  - Submit this result as a patch against the second email.
  - When the module is unloaded, all of the debugfs files are cleaned
    up, and any memory allocated is freed, for all submissions.
  - Provide some "proof" this all works in the first email.

Again, you are using your id in the code, so you know what it is by now,
no need to repeat it again.

So, for this task, I expect to see 3 emails, all "linked" somehow, in my
mailbox.  They should look something like this:

        [YOUR_ID] Task 08 results
        ├─>[YOUR_ID] [PATCH 01/02] Task 08: add jiffies file
        └─>[YOUR_ID] [PATCH 02/02] Task 08: add foo file

Or, even better:
        [YOUR_ID] Task 08 results
        └─>[YOUR_ID] [PATCH 01/02] Task 08: add jiffies file
          └─>[YOUR_ID] [PATCH 02/02] Task 08: add foo file

Hint, look at using 'git send-email' as a way to send these files out.

This is Task 09 of the Eudyptula Challenge
------------------------------------------

Nice job with debugfs.  That is a handy thing to remember when wanting
to print out some debugging information.  Never use /proc/ that is only
for processes, use debugfs instead.

Along with debugfs, sysfs is a common place to put information that
needs to move from the user to the kernel.  So let us focus on sysfs for
this task.

The tasks this time:

  - Take the code you wrote in task 08, and move it to sysfs.  Put the
    "eudyptula" directory under the /sys/kernel/ location in sysfs.
  - fix up the permissions of the files to not allow world writable
    values, but only be able to be written to by root.
  - Provide some "proof" this works.

That's it!  Simple, right?  No, you are right, it's more complex; sysfs
is complicated.  I'd recommend reading Documentation/kobject.txt as a
primer on how to use kobjects and sysfs.

Feel free to ask for hints and help with this one if you have questions
by sending in code to review if you get stuck.  Many people have dropped
out in the challenge at this point in time, so don't feel bad about
asking.  We don't want to see you go away just because sysfs is so damn
complicated.

This is Task 10 of the Eudyptula Challenge
------------------------------------------

Yeah, you conquered the sysfs monster, great job!

Now you know you'll never want to mess with a kobject again, right?
Trust me, there are easier ways to create sysfs files, and we will get
into that for a future task, but for now, let's make it a bit more
simple after all of that coding.

For these tasks, go back to the linux-next tree you used for task 07.
Update it, and then do the following:
  - Create a patch that fixes one coding style problem in any of the
    files in drivers/staging/
  - Make sure the patch is correct by running it through
    scripts/checkpatch.pl
  - Submit the code to the maintainer of the driver/subsystem, finding
    the proper name and mailing lists to send it to by running the tool,
    scripts/get_maintainer.pl on your patch.
  - Get the patch accepted into the subsystem maintainers git tree.
  - Send a web link back to me of your patch in the public mailing list
    archive (don't cc: me on the patch, that will only confuse me and
    everyone in the kernel development community) as well as a pointer
    to the git commit of your patch in the subsystem tree.

Hopefully this patch will be accepted into the kernel tree, and all of a
sudden, you are an "official" kernel developer!

Don't worry, there's plenty more tasks coming, but a little breather
every now and again for something simple is always nice to have.

This is Task 11 of the Eudyptula Challenge
------------------------------------------

You made a successful patch to the kernel source tree, that's a great
step!

But, let's not rest, time to get back to code.

Remember that mess of kobject and sysfs code back in task 09?  Let's
move one level up the tree and start to mess with devices and not raw
kobjects.

For this task:
  - Write a patch against any driver that you are currently using on
    your machine.  So first you have to figure out which drivers you are
    using, and where the source code in the kernel tree is for that
    driver.
  - In that driver, add a sysfs file to show up in the /sys/devices/
    tree for the device that is called "id".  As you might expect, this
    file follows the same rules as task 09 as for what you can read and
    write to it.
  - The file is to show up only for devices that are controlled by a
    single driver, not for all devices of a single type (like all USB
    devices.  But all USB mailbox LEDs would be acceptable, if you
    happen to have the device that that driver controls.)

Submit both the patch, in proper kernel commit form, and "proof" of it
working properly on your machine.

And as always, please use your id in the subject line.  If you happened
to forget it, as it has been a while since I reminded you of it, it is
"YOUR_ID".

This is Task 12 of the Eudyptula Challenge
------------------------------------------

Nice job with the driver patch.  That took some work in finding the
proper place to modify, and demonstrates a great skill in tracking down
issues when you can't get a specific piece of hardware working.

Now let's step back from drivers (they are boring things), and focus on
the kernel core.  To do that, we need to go way back to the basics --
stuff you would learn in your "intro to data structures" class, if you
happened to take one.

Yes, I'm talking about linked lists.

The kernel has a unique way of creating and handling linked lists, that
is quite different than the "textbook" way of doing so.  But, it turns
out to be faster, and simpler, than a "textbook" would describe, so
that's a good thing.

For this task, write a kernel module, based on your cleaned up one from
task 04, that does the following:
  - You have a structure that has 3 fields:
        char  name[20];
        int   id;
        bool  busy;
    name this structure "identity".
  - Your module has a static variable that points to a list of these
    "identity" structures.
  - Write a function that looks like:
        int identity_create(char *name, int id)
    that creates the structure "identity", copies in the 'name' and 'id'
    fields and sets 'busy' to false.  Proper error checking for out of
    memory issues is required.  Return 0 if everything went ok; an error
    value if something went wrong.
  - Write a function that looks like:
        struct identity *identity_find(int id);
    that takes a given id, iterates over the list of all ids, and
    returns the proper 'struct identity' associated with it.  If the
    identity is not found, return NULL.
  - Write a function that looks like:
        void identity_destroy(int id);
    that given an id, finds the proper 'struct identity' and removes it
    from the system.
  - Your module_init() function will look much like the following:

        struct identity *temp;

        identity_create("Alice", 1);
        identity_create("Bob", 2);
        identity_create("Dave", 3);
        identity_create("Gena", 10);

        temp = identity_find(3);
        pr_debug("id 3 = %s\n", temp->name);

        temp = identity_find(42);
        if (temp == NULL)
                pr_debug("id 42 not found\n");

        identity_destroy(2);
        identity_destroy(1);
        identity_destroy(10);
        identity_destroy(42);
        identity_destroy(3);

   Bonus points for properly checking return values of the above
   functions.

As always, please send the full module (following the proper kernel
coding style rules), and "proof" of it working properly.  And remember
to use your id of "YOUR_ID" in the Subject line properly.

This is Task 13 of the Eudyptula Challenge
------------------------------------------

Weren't those lists fun to play with?  You should get used to them, they
are used all over the kernel in lots of different places.

Now that we are allocating a structure that we want to use a lot of, we
might want to start caring about the speed of the allocation, and not
have to worry about the creation of those objects from the "general"
memory pools of the kernel.

This task is to take the code written in task 12, and cause all memory
allocated from the 'struct identity' to come from a private slab cache
just for the fun of it.

Instead of using kmalloc() and kfree() in the module, use
kmem_cache_alloc() and kmem_cache_free() instead.  Of course this means
you will have to initialize your memory cache properly when the module
starts up.  Don't forget to do that.  You are free to name your memory
cache whatever you wish, but it should show up in the /proc/slabinfo
file.

Don't send the full module for this task, only a patch with the diff
from task 12 showing the lines changed.  This means you will have to
keep a copy of your 12 task results somewhere to make sure you don't
overwrite them.

Also show the output of /proc/slabinfo with your module loaded.

This is Task 14 of the Eudyptula Challenge
------------------------------------------

Now that you have the basics of lists, and we glossed over the custom
allocators (the first cut at that task was much harder, you got off
easy), it's time to move on to something a bit more old-school: tasks.

For this task:
  - Add a new field to the core kernel task structure called, wait for
    it, "id".
  - When the task is created, set the id to your id.  Imaginative, I
    know.  You try writing these tasks.
  - Add a new proc file for every task called, "id", located in the
    /proc/${PID}/ directory for that task.
  - When the proc file is read from, have it print out the value of
    your id, and then increment it by one, allowing different tasks to
    have different values for the "id" file over time as they are read
    from.
  - Provide some "proof" it all works properly.

As you are touching files all over the kernel tree, a patch is the
required result to be sent in here.  Please specify which kernel version
you make this patch against, to give my virtual machines a chance to
figure out how to apply it.

Also provide some kind of proof that you tested the patch.

And, in case you happened to forget it, your id is "YOUR_ID".

This is Task 15 of the Eudyptula Challenge
------------------------------------------

That process task turned out to not be all that complex, but digging
through the core kernel was a tough task, nice work with that.

Speaking of "core kernel" tasks, let's do another one.  It's one of the
most common undergraduate tasks there is: create a new syscall!
Yeah, loads of fun, but it's good to know the basics of how to do this,
and, how to call it from userspace.

For this task:
  - Add a new syscall to the kernel called "sys_eudyptula", so this is
    all going to be changes to the kernel tree itself, no stand-alone
    module needed for this task (unless you want to do it that way
    without hacking around the syscall table, if so, bonus points for
    you...)
  - The syscall number needs to be the next syscall number for the
    architecture you test it on (some of you all are doing this on ARM
    systems, showoffs, and syscall numbers are not the same across all
    architectures).  Document the arch you are using and why you picked
    this number in the module.
  - The syscall should take two parameters: int high_id, int low_id.
  - The syscall will take the two values, mush them together into one
    64bit value (low_id being the lower 32bits of the id, high_id being
    the upper 32bits of the id).
  - If the id value matches your id (which of course you know as
    "a24a6bdd6a14", then the syscall returns success.  Otherwise it
    returns a return code signifying an invalid value was passed to it.
  - Write a userspace C program that calls the syscall and properly
    exercises it (valid and invalid calls need to be made).
  - "Proof" of running the code needs to be provided.

So you need to send in a .c userspace program, a kernel patch, and
"proof" that it all works, as a response.


This is Task 16 of the Eudyptula Challenge
------------------------------------------

Good job with the new syscall.  The odds of you ever having to write a
new syscall is pretty rare, but now you know where to look them up, and
what the code involved in creating one looks like, which is useful when
you try to debug things.

Let's take a breather after all of that code, and go back to doing a bit
of reading, and learn some more about some common kernel tools.

Go install the tool 'sparse'.  It was started by Linus as a
static-analysis tool that acts much like a compiler.  The kernel build
system is set up to have it run if you ask it to, and it will report a
bunch of issues in C code that are really specific to the kernel.

When you build the kernel, pass the "C=1" option to the build, to have
sparse run on the .c file before gcc is run.  Depending on the file,
nothing might be printed out, or something might.  Here's an example of
it being run on the ext4 code:

$ make C=1 M=fs/ext4
  CHECK   fs/ext4/balloc.c
  CC      fs/ext4/balloc.o
  CHECK   fs/ext4/bitmap.c
  CC      fs/ext4/bitmap.o
  CHECK   fs/ext4/dir.c
  CC      fs/ext4/dir.o
  CHECK   fs/ext4/file.c
  CC      fs/ext4/file.o
  CHECK   fs/ext4/fsync.c
  CC      fs/ext4/fsync.o
  CHECK   fs/ext4/ialloc.c
  CC      fs/ext4/ialloc.o
  CHECK   fs/ext4/inode.c
  CC      fs/ext4/inode.o
  CHECK   fs/ext4/page-io.c
  CC      fs/ext4/page-io.o
  CHECK   fs/ext4/ioctl.c
  CC      fs/ext4/ioctl.o
  CHECK   fs/ext4/namei.c
  CC      fs/ext4/namei.o
  CHECK   fs/ext4/super.c
  CC      fs/ext4/super.o
  CHECK   fs/ext4/symlink.c
  CC      fs/ext4/symlink.o
  CHECK   fs/ext4/hash.c
  CC      fs/ext4/hash.o
  CHECK   fs/ext4/resize.c
  CC      fs/ext4/resize.o
  CHECK   fs/ext4/extents.c
  CC      fs/ext4/extents.o
  CHECK   fs/ext4/ext4_jbd2.c
  CC      fs/ext4/ext4_jbd2.o
  CHECK   fs/ext4/migrate.c
  CC      fs/ext4/migrate.o
  CHECK   fs/ext4/mballoc.c
fs/ext4/mballoc.c:5018:9: warning: context imbalance in 'ext4_trim_extent' - unexpected unlock
  CC      fs/ext4/mballoc.o
  CHECK   fs/ext4/block_validity.c
  CC      fs/ext4/block_validity.o
  CHECK   fs/ext4/move_extent.c
  CC      fs/ext4/move_extent.o
  CHECK   fs/ext4/mmp.c
  CC      fs/ext4/mmp.o
  CHECK   fs/ext4/indirect.c
  CC      fs/ext4/indirect.o
  CHECK   fs/ext4/extents_status.c
  CC      fs/ext4/extents_status.o
  CHECK   fs/ext4/xattr.c
  CC      fs/ext4/xattr.o
  CHECK   fs/ext4/xattr_user.c
  CC      fs/ext4/xattr_user.o
  CHECK   fs/ext4/xattr_trusted.c
  CC      fs/ext4/xattr_trusted.o
  CHECK   fs/ext4/inline.c
  CC      fs/ext4/inline.o
  CHECK   fs/ext4/acl.c
  CC      fs/ext4/acl.o
  CHECK   fs/ext4/xattr_security.c
  CC      fs/ext4/xattr_security.o
  LD      fs/ext4/ext4.o
  LD      fs/ext4/built-in.o
  Building modules, stage 2.
  MODPOST 0 modules

As you can see, only one warning was found here, and odds are, it is a
false-positive, as I'm sure those ext4 developers know what they are
doing with their locking functions, right?

Anyway the task this time is:
  - Run sparse on the drivers/staging/ directory, yes, that horrible
    code again, sorry.
  - Find one warning that looks interesting.
  - Write a patch that resolves the issue.
  - Make sure the patch is correct by running it through
    scripts/checkpatch.pl
  - Submit the code to the maintainer of the driver/subsystem, finding
    the proper name and mailing lists to send it to by running the tool,
    scripts/get_maintainer.pl on your patch.
  - Work with the maintainer to get the patch accepted into their tree.
  - Send a web link back to me of your patch in the public mailing list
    archive (don't cc: me on the patch, that will only confuse me and
    everyone in the kernel development community) as well as a pointer
    to the patch in the maintainer's public git tree.

That's it, much like task 10 was, but this time you are fixing logical
issues, not just pesky coding style issues.  You are a real developer
now, fixing real bugs!

