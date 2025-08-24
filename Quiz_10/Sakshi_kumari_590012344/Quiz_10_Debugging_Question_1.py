1. Identify the bug in the sorting criteria 
The bug lies in the sorting criteria. The activities are currently being sorted by their start time (activities.sort(key=lambda x: x[0])),
but the greedy strategy for the Activity Selection Problem requires sorting by finish time instead.


2. Why this causes suboptimal results
When you sort by start time, the algorithm may pick an activity that starts early but finishes late,
blocking other shorter activities that could have allowed more non-overlapping selections.
This causes suboptimal results because the greedy property is violated — the correct choice should always be the activity that finishes earliest, leaving maximum room for future activities.

To fix this, the sort line should be:   
activities.sort(key=lambda x: x[1])
This ensures the algorithm picks activities in the order of their finishing times, which guarantees the maximum number of non-overlapping activities.  
