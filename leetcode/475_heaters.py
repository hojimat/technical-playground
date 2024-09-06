class Solution:
    def findRadius(self, houses: list[int], heaters: list[int]) -> int:
        houses.sort()
        heaters.sort()
        Nheat = len(heaters) - 1
        radius = 0
        i = 0

        for house in houses:
            while i < Nheat and abs(heaters[i] - house) >= abs(heaters[i+1] - house):
                i += 1
            radius = max(radius, abs(heaters[i] - house))

        return radius