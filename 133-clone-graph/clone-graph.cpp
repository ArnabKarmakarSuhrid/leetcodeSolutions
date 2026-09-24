

class Solution {
public:
    unordered_map<Node*, Node*> clones;
    Node* cloneGraph(Node* node) {

        if(node == nullptr){
            return nullptr;
        }
            if(clones.count(node)){
            return clones[node];
            }
            Node* clonedNode = new Node(node->val);

            clones[node] = clonedNode;

            for(Node* neighbor : node->neighbors){
                 clonedNode->neighbors.push_back(
                    cloneGraph(neighbor)

                 );
            }
        
        return clonedNode;

        
    }
};