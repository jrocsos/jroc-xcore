from CORE.system import JROCSystem



class BrainKernel:


    def __init__(self):

        self.system = JROCSystem()

        self.memory = []

        self.commands = []



    def boot(self):

        return self.system.boot()



    def think(
        self,
        input_data
    ):

        decision = {

            "input":
            input_data,

            "action":
            "PROCESSING"

        }


        self.memory.append(
            decision
        )


        return decision



    def remember(
        self,
        data
    ):

        self.memory.append(data)



    def recall(self):

        return self.memory



    def status(self):

        return {

            "brain":
            "ACTIVE",

            "memory":
            len(self.memory)

        }
