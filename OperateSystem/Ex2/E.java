package io.github.jayin.ProcessorScheduling;


import java.util.ArrayList;
import java.util.List;

/**
 * Created by jayin on 14/12/11.
 */
public class E {

    public static List<Pcb> pcbs = new ArrayList<Pcb>();

    public static void main(String[] args){
            RoundRobin(1);
            RoundRobin(4);
    }
    /**
     * 判断是否完成所有任务
     * @return
     */
    public static boolean isFinish(){
        for(Pcb pcb : pcbs){
            if(pcb.left_time > 0 ){
                return false;
            }
        }
        return true;

    }
    ////////////
    /**
     * 时间片轮转法 RR
     */
    public static void RoundRobin(int T){
        pcbs.clear();
        pcbs.add(new Pcb("A",0,12));
        pcbs.add(new Pcb("B",0,5));
        pcbs.add(new Pcb("C",0,3));
        pcbs.add(new Pcb("D",0,6));

        int cur_time = 0 ;
        ArrayList<String> queue = new ArrayList<String>();

        while(!isFinish()){
            for(Pcb pcb : pcbs){
                if(pcb.left_time > 0 ){
                    //add to queue
                    queue.add(pcb.name);

                    if(pcb.start_time < 0 ){
                        pcb.start_time = cur_time;
                    }

                    if(pcb.left_time - T > 0){
                        cur_time += T;
                        pcb.left_time = pcb.left_time - T;
                    }else if(pcb.left_time - T == 0){
                        cur_time += T;
                        pcb.left_time = pcb.left_time - T;
                        pcb.finish_time = cur_time;
                        pcb.turnover_time = pcb.finish_time - pcb.reach_time;
                        pcb.power_time = pcb.turnover_time * 1.0 / pcb.run_time;
                    }else{
                        cur_time +=pcb.left_time;
                        pcb.left_time = 0;
                        pcb.finish_time = cur_time;
                        pcb.turnover_time = pcb.finish_time - pcb.reach_time;
                        pcb.power_time = pcb.turnover_time * 1.0 / pcb.run_time;
                    }
                }
            }
        }
        int total_T = 0;
        double total_W = 0;
        for(Pcb pcb : pcbs){
            total_T +=pcb.turnover_time;
            total_W +=pcb.power_time;
            String r = String.format("%s %2d %2d %2d %2d %2d %.2f",pcb.name,pcb.reach_time,pcb.run_time,pcb.start_time,pcb.finish_time,pcb.turnover_time,pcb.power_time);
            System.out.println(r );
        }
        System.out.printf("平均周转时间:%.2f 平均带权周转时间:%.2f \n",total_T * 1.0 /pcbs.size(),total_W * 1.0/pcbs.size());
        System.out.println("调度顺序");
        for(String name : queue){
            System.out.print(name +"->");
        }
        System.out.println("Finish");
        System.out.println();
    }
}




