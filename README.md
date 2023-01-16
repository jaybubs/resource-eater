# Resource Eater

This is an adaptation of the [C-based CPU/MEM app](https://electronproton.com/cpu-mem-load-test/).

The main differences are:

- Using cpp instead
- calloc (or malloc for that matter) can allocate crazy amounts of virt ram without actually consuming it, even after copying stuff into it - and I'm honestly not sure why. So I've replaced the the memory consumtion with std::deque. Deque was chosen simply because I might not have 16 gigs of contiguous ram available to me, but with deque that's not an issue
- The program will terminate after the limited time using the while condition as opposed to a SIGALRM
- The app is built statically

The main drivers for this app and/or modifications were to have a program that's as simple as possible, that will strain a single CPU and consume some memory for k8s cluster monitoring purposes (via prometheus). It has not been (un)optimised to load test a cluster.

An example job spec is present on its deployment.
