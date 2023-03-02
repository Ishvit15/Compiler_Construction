void generateFollowSet(){
    bool change = TRUE;
    addToSet(followSet[PROGRAM], END_OF_FILE);
    while(change == TRUE){
        change = FALSE;
        for(int i=0; i<TOTAL_RULES; i++){
            rhsOfGrammarRuleNode * A = rules[i];
            rhsOfGrammarRuleNode *t = rules[i]->next;

            while(t!=NULL){
                if(t->symbol.tno == EPSILON) break;
                while(t!=NULL && t->symbol.isTerminal==TRUE){
                    t = t->next;
                }
                if(t==NULL) break;
                bool new_foll[TERMINALS_COUNT];
                
                if(t->next == NULL){ //A -> aB
                    unionOfSets(new_foll, new_foll, followSet[A->symbol.ntno]);
                    break;
                }
                else{ //t->next !=NULL
                    rhsOfGrammarRuleNode *t1 = t->next;

                    while(t1!= NULL){
                        if(t1->symbol.isTerminal==TRUE){
                            addToSet(new_foll, t1->symbol.tno);
                        }
                        else{
                             //t1 is a non-terminal
                            if(findElementInSet(firstSet[t1->symbol.ntno], EPSILON) ==FALSE){
                                unionOfSets(new_foll, new_foll, firstSet[t1->symbol.ntno]);
                                t1 = t1->next;
                                break;
                            }
                            else{
                                //t1 has EPSILON
                                unionOfSets(new_foll, new_foll, firstSet[t1->symbol.ntno]);
                                deleteFromSet(new_foll, EPSILON);

                                if(t1->next == NULL){
                                    unionOfSets(new_foll, new_foll, followSet[A->symbol.ntno]);
                                    t1= t1->next;
                                    break;
                                }
                                else{
                                    //t1->next != NULL
                                    t1 = t1->next;
                                }
                            }
                        }
                    }
                }

            for(int j=0; j<TERMINALS_COUNT; j++){
                if(new_foll)
            }
            }
        }
    }
}
