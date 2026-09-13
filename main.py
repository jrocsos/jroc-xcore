from CORE.brain.kernel import BrainKernel

from AGENTS.factory.factory import AgentFactory

from CORE.swarm.controller import SwarmController

from CITY.knowledge_center.database import KnowledgeDatabase

from CITY.knowledge_center.vault import KnowledgeVault

from CORE.memory.brain_memory import BrainMemory

from CORE.memory.experience import ExperienceSystem

from CORE.evolution.manager import VersionManager

from CORE.evolution.upgrader import UpgradeLoader

from CORE.evolution.history import EvolutionHistory

from AGENTS.skills.skill_tree import SkillTree

from CITY.city_core import JROCCity

from CITY.command_tower.control import CommandTower

from CITY.districts.manager import DistrictManager

from CITY.departments.system import DepartmentSystem

from CITY.workspaces.manager import WorkspaceManager

from CITY.population.registry import PopulationRegistry



JROC = BrainKernel()

factory = AgentFactory()

swarm = SwarmController()

knowledge = KnowledgeDatabase()

vault = KnowledgeVault()

memory = BrainMemory()

experience = ExperienceSystem()

versions = VersionManager()

upgrades = UpgradeLoader()

history = EvolutionHistory()

skills = SkillTree()

city = JROCCity()

tower = CommandTower()

districts = DistrictManager()

departments = DepartmentSystem()

workspaces = WorkspaceManager()

population = PopulationRegistry()



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


print(
"\nJROC EVOLUTION"
)


print(
versions.version()
)


print(
versions.upgrade()
)


upgrade = upgrades.load(

    "v002",

    "Agent Communication"

)


history.record(
    upgrade
)


skills.add_skill(

    "Atlas",

    "Advanced Research"

)


print(
"\nUPGRADE:"
)

print(
upgrade
)


print(
"\nSKILLS:"
)

print(
skills.get_skills("Atlas")
)


print(
"\nSTARTING JROC CITY"
)


print(
city.activate()
)


departments.create(
"Research"
)

departments.create(
"Engineering"
)

departments.create(
"Security"
)


districts.create(
"North District",
"Research Operations"
)

districts.create(
"East District",
"Engineering Operations"
)


tower.issue(
"All agents report to command tower"
)


for agent in agents:

    population.add(agent)

    workspaces.create(
        agent.name
    )


city.population = population.count()


print(
"\nCITY REPORT"
)

print(
city.report()
)


print(
"\nPOPULATION"
)

print(
population.list()
)
