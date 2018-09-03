// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto IndexToMoveNow = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	auto PatrolRoute = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRoute>();

	if (PatrolRoute == nullptr) { return EBTNodeResult::Succeeded; }

	if(PatrolRoute->GetPatrolPoint().Num() <= 0){ return EBTNodeResult::Succeeded; }

	auto WayPointToMove = PatrolRoute->GetPatrolPoint()[IndexToMoveNow];

	BlackBoardComp->SetValueAsObject(Waypoint.SelectedKeyName, WayPointToMove);

	//Set Cycle index
	auto NewIndex = (IndexToMoveNow + 1) % (PatrolRoute->GetPatrolPoint().Num());
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NewIndex);
	
	return EBTNodeResult::Succeeded;
}
