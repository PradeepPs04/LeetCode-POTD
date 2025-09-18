// https://leetcode.com/problems/design-task-manager/description/?envType=daily-question&envId=Invalid%20Date

class TaskManager {
private:
    unordered_map<int, int>taskPriority; // {taskId: priority}
    unordered_map<int, int>taskOwner; // {taskId: userId}
    priority_queue<pair<int, int>>pq; // max heap
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks) {
            int userId = it[0];
            int taskId = it[1];
            int priority = it[2];

            taskPriority[taskId] = priority;
            taskOwner[taskId] = userId;
            pq.push({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskPriority[taskId] = priority;
        taskOwner[taskId] = userId;
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        taskPriority[taskId] = newPriority;
        int userId = taskOwner[taskId];
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskPriority[taskId] = -1;
        taskOwner[taskId] = -1;
    }
    
    int execTop() {
        while(!pq.empty()) {
            int topPriority = pq.top().first;
            int topTaskId = pq.top().second;

            if(taskPriority[topTaskId] == topPriority)  break;

            pq.pop();
        }

        if(pq.empty())  return -1;

        // execute & remove task
        int topPriority = pq.top().first;
        int topTaskId = pq.top().second;
        int topUserId = taskOwner[topTaskId];
        
        pq.pop();
        
        taskPriority[topTaskId] = -1;
        taskOwner[topTaskId] = -1;

        return topUserId;
    }
};