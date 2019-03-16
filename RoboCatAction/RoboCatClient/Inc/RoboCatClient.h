class RoboCatClient : public RoboCat
{
public:
	static	GameObjectPtr	StaticCreate()		{ return GameObjectPtr( new RoboCatClient() ); }

	virtual void Update();
	virtual void	HandleDying() override;

	virtual void	Read( InputMemoryBitStream& inInputStream ) override;

protected:
	RoboCatClient();


private:
	float				mTimeLocationBecameOutOfSync;
	float				mTimeVelocityBecameOutOfSync;
	
	SpriteComponentPtr	mSpriteComponent;

	//Move	mClientsLastProcessedMove;
	//std::vector<std::pair<Move, float>>				mClientsLastProcessedMove;
	float				mLastSavedServerTimestamp;
};