## Lab 8
### Samm Katcher
### 3/24/17

#### Make sure you write up in a lab report (as markdown file in your github page) about what you changed, 
#### why it is important to maintain good documentation, and what you have learned from this lab.


We made 3 changes on this page:
https://www.freebsd.org/cgi/man.cgi?query=ral&apropos=0&sektion=0&manpath=FreeBSD+11.0-RELEASE+and+Ports&arch=default&format=html

and 1 change on this page:
https://www.freebsd.org/cgi/man.cgi?query=wlan&apropos=0&sektion=4&manpath=FreeBSD+11.0-RELEASE+and+Ports&arch=default&format=html

#### Links:
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=218070


#### We submitted changes for changing the word "an" to the word "a" in one sentence, 
#### the word "adapters" to the word "adapter," 
#### and two sentence restructures.

#### The sentence was:   
Some PCI ral adapters seem	to strictly require a system supporting	PCI 
2.2 or greater and	will likely not	work in	systems	based on older revi-
sions of the PCI specification.

#### Revision:
Some PCI ral adapters strictly require a system that supports	PCI 2.2 or greater.
The adapter will not work in	systems	based on older revisions of the PCI specification.


#### The sentence was:
Beware that this specification is	incompatible with earlier drafts;
and stations implementing earlier drafts (e.g. Linux) may not interoperate.

#### Revision:
Be aware that this specification is incompatible with earlier drafts.
Stations implementing earlier drafts (e.g. Linux) may be incompatible.


#### Why Documentation is Important
It is important to have good doucmentation that way future developers who use your code (yourself included) 
remember and know what the code specifically does.
The best reason to write good personal documentation is because you will be using your code in the future. 
Code that you wrote 6 months ago is often indistinguishable from code that someone else has written. The goal of documentation
is to help understand your code. So when there is bad documentation, it can often make the code even more confusing.

#### What I learned
I learned how to submit changes to FreeBSD and how that it is important to contribute back to the documentation
in communities if you notice things. I also learned how important the place for writers and documentors in open source communities really is.
