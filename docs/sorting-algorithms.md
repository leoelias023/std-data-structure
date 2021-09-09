# Sorting algorithms

Here you can found annotations about existing sorting algorithms and links to the implementation.

## Bubble sort

The most simple (I think) following the correct steps make this work fine.

### Use case for this

- A set of data ordered (or near this), it isn't the case performance will be bad (really bad).

### How it works?

Iterate each index of the set of data and verify if the current element is bigger than the next
element, if it is the case, re-order this (place the current element in the index of the next), however
it will init a cycle.

Yes, the above cycle will stop when all data is completely sorted as expected.

<img width="500" src="../assets/bubble-sort-sample.png" />

### Implementation

Open this [file code](../code/sorting-algorithms/bubble-sort.c).

## Insertion sort

The insertion sort compared with Bubble sort in some situations, like a new insert of data in a set of cards that already is ordered (e. g. like a new card incoming in a ordered deck).

### How it works?

With the second element of the set, iterate all the items verifying if the elements left side elements are bigger than the current value, move that to the right.

### Implementation

Open this [file code](../code/sorting-algorithms/insertion-sort.c).

## Selection sort

Pick the minor value and put on the place of the current initial index, ordering totally.

### How it works?

```
Non ordered: [3,1,6,4]

Step 1:
  - Current index: 0
  - Minor value: 1
  - Set: [1,3,6,4]

Step 2:
  - Current index: 1
  - Minor value: 3
  - Set: [1,3,6,4]

Step 3:
  - Current index: 2
  - Minor value: 4
  - Set: [1,3,4,6]

Step 4:
  - Current index: 3
  - Minor value: 6
  - Set: [1,3,4,6]

Happy =) Ordered successfully
```

### Implementation

A simple implementation in C language, open [here](./code/sorting-algorithms/selection-sort.c)
