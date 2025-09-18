#   1. Missing the "visited" check. Without it, nodes may be processes multiple times.

#   2. It still updates the distances correctly using relaxation, but unnecessary pushes to priority queue slow it down.

#   3. It returns the correct shortest distances, but with redundant work. Same node may re-enter the queue many times,, making it
#      inefficient. 
