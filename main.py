from CORE.brain.kernel import BrainKernel

from AGENTS.factory.factory import AgentFactory

from CORE.swarm.controller import SwarmController

from CITY.knowledge_center.database import KnowledgeDatabase

from CITY.knowledge_center.vault import KnowledgeVault

from CORE.memory.brain_memory import BrainMemory

from CORE.memory.experience import ExperienceSystem



JROC = BrainKernel()

factory = AgentFactory()

swarm = SwarmController()

knowledge = KnowledgeDatabase()

vault = KnowledgeVault()

memory = BrainMemory()

experience = ExperienceSystem()



print(
JROC.boot()
)



# Create JROC Workforce

agents = [

    factory.create(
        "Atlas",
        "research"
    ),

    factory.create(
        "Forge",
        "builder"
    ),

    factory.create(
        "Guardian",
        "security"
    ),

    factory.create(
        "Oracle",
        "strategy"
    )

]



for agent in agents:

    swarm.add(agent)



print(
"\nJROC SWARM:"
)


print(
swarm.status()
)



mission=input(

"\nMission: "

)



results = swarm.deploy(
    mission
)



print(
"\nRESULTS:"
)


for result in results:

    print(result)


memory.remember(results)


vault.add(results)


knowledge.store(
    mission,
    results
)


for agent in agents:

    experience.record(agent)


print(
"\nJROC MEMORY STATUS"
)

print(
"Memories:",
memory.count()
)


print(
"Knowledge Entries:",
len(knowledge.all())
)


print(
"Agent Experience:"
)

print(
experience.status()
)
