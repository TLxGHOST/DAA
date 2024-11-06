import java.util.Collections;
import java.util.List;

class RobotProblem {
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
           Collections.sort(robot);
           long distance = 0L; 
           for (int i = 0; i < robot.size(); i++)
           {    
                int postionOfRobot=robot.get(i);
                for(int j=0;j<factory.length; j++)
                {
                    if(factory[i][2]!=0)
                    {
                        //factory has remaining orders
                        if (true) {
                            //if it is closest
                        }
                        else 
                        continue;
                    }
                    else
                    //factory is full]\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
                    continue;

                }

           }
           return distance; // Return the calculated distance
    }
}