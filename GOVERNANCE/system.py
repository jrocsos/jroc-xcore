class GovernanceSystem:


    def __init__(self):

        self.rules = []

        self.leaders = []



    def create_rule(
        self,
        rule
    ):

        self.rules.append(rule)



    def appoint_leader(
        self,
        agent
    ):

        self.leaders.append(agent)



    def report(self):

        return {

            "rules":
            self.rules,

            "leaders":
            self.leaders

        }
