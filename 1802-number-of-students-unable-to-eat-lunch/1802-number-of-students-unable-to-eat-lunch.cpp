class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circleStudentCount=0,squareStudentCount=0;
        for(auto i:students) {
            if(i==1)
                squareStudentCount++;
            else
                circleStudentCount++;
        }
        for(auto i:sandwiches) {
            if(i==1) {
                if(squareStudentCount>0)
                    squareStudentCount--;
                else
                    break;
            }
            if(i==0) {
                if(circleStudentCount>0)
                    circleStudentCount--;
                else
                    break;
            }
        }
        return squareStudentCount+circleStudentCount;
    }
};