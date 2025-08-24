#  1.  The bug in the sorting criteria is that the code sorts activities by their start time using which is wrong. Sorting should be done
#      according to the end time of the activities in increasing order.
 
#  2.  Sorting by start time may select an early activity that ends late , thus blocking multiple shorter activities that could fit later.
#      Therefore, the correct approach is to sort activities by "end" time, i.e., "activities.sort(key = lambda x : x [1])". This ensures
#      that the earliest finishing activity is picked first, maximizing the number of non-overlapping activities.

#      Here's the corrected code : 

#      def activity_selection(start, end):
#          n = len(start)
#          activities = []
#      
#          for i in range(n):
#              activities.append((start[i], end[i], i))
#      
#          # Sort by end time (correct approach)
#          activities.sort(key=lambda x: x[1])
#      
#          selected = [activities[0]]
#          last_end = activities[0][1]
#      
#          for i in range(1, n):
#              if activities[i][0] >= last_end:
#                  selected.append(activities[i])
#                  last_end = activities[i][1]
#      
#          return len(selected)
#      
#      # Test case:
#      start = [1, 3, 0, 5, 8, 5]
#      end = [2, 4, 6, 7, 9, 9]
#      result = activity_selection(start, end)
#      print(f"Maximum activities: {result}")
