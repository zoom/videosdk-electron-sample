const CmdTypes = {
	cmd_none: 0,
	cmd_reaction: 1,
	cmd_feedback_push: 2,
	cmd_feedback_submit: 3,
	cmd_lowerthird: 4
}

const ReactionTypes = {
	clap: 1,
	thumbsup: 2,
	joy: 3,
	hushed: 4,
	heart: 5,
	tada: 6,
	raisehand: 7
}

const FeedbackTypes = {
	verySatisfied: 'Very Satisfied',
	satisfied: 'Satisfied',
	neutral: 'Neutral',
	unsatisfied: 'Unsatisfied',
	veryUnsatisfied: 'Very Unsatisfied'
}

module.exports = {
	CmdTypes,
	ReactionTypes,
	FeedbackTypes
}
