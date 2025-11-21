# Project 5 Report

Answer the following prompts directly in this file:
* Information about your dataset. You will be assigned a different grader for this project.
My data set is filled with 10000 student objects, each with a non-unique college ID, a boolean internship experience, a boolean placement, an IQ, an academic performance, an extra curricular score, a score on communication skills, the amount of projects completed, a unique number (1 through 10000), a previous semester GPA and finally a cumulative GPA.

* Which Open Addressing hash tables change size during the program? Why?
  I created 5 different initial sizes, with the first 3 sizes being 1.1, 1.4 and 1.9 times the size of the data set (in that respective order), which is 10000 students. The last 2 table sizes were 2.2 and 2.5 times the size of the data set. Therefore, when the cout results showed that the first three tables in both Open Addressing hash tables changed size during the program while the last 2 tables didn't, it was because the first 3 tables weren't at least double the size of the data set, therefore they needed to be doubled and increased to the closest prime number during rehashing.
  
* Create graphs for the number of collisions for inserting your dataset into all 20 hash tables.
  * Clearly label the graph titles and axes.
  * Set up the graph in a way that makes the most sense to you. Here are some options I have seen before:
    * Using a line graph to track the *individual* collision counts as each insertion is made. High-valued blips happen in open addressing when rehashes occur.
    * Using a line graph to track the *cumulative* collision count as each insertion is made. Vertical jumps happen in open addressing when rehashes occur.
    * Using a line graph to track the *average* number of collisions per insertion, where each hash table has one value and you can see the trends as the initial table size grows.
* Using the graphs, analyze why the collision counts are different for the different size hash tables. Use what you know about your keys and the hash tables to justify why the collision counts make sense.
Based off the graphed data, we can see that collision counts of open addressing are almost double those of separate chaining. This is because during separate chaining, if an index collides with another index, this results in a single collision, then the new index is simply just chained from the old index. However, in open addressing, when an index collides with another index, it must find another empty slot by probing through neighboring indexes until said index is empty. This probing can cause more collisions if the index tries to occupy multiple indexes that are already occupied. Therefore, the collision rate is much higher for open addressing than it is for separate chaining.
* Determine which global function works best as the key for your dataset objects based on the collision counts.
Based off of the different graph results, the ID key resulted in slightly less collisions than the IQ key (about 400 less for separate chaining and 200 less for open addressing). Therefore, it seems that the ID key had better results in terms of collisions than the IQ key.
* Draw conclusions about which hash collision detection method works best on your dataset (separate chaining or open addressing).
Based off of my analysis of the data from both separate chaining and open addressing over my College Student dataset, it is clear that separate chaining worked better in terms of producing less collisions, resulting in a more efficient hashing system.


**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**
