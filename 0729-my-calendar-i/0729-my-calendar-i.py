class MyCalendar:

    def __init__(self):
        self.events = []

    def book(self, startTime, endTime):
        for start, end in self.events:

            # Check for overlap
            if startTime < end and endTime > start:
                return False

        self.events.append((startTime, endTime))
        return True